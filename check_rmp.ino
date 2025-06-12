const byte encoderPin = 2;  // encoder output A
volatile unsigned int pulseCount = 0;
unsigned long lastTime = 0;
float rpm = 0;
int pulsesPerRevolution = 1000;  // ขึ้นอยู่กับ encoder ของคุณ

void setup() {
  pinMode(encoderPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPin), countPulse, RISING);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastTime >= 1000) {  // คำนวณทุก 1 วินาที
    rpm = (pulseCount * 60.0) / pulsesPerRevolution;  // แปลงเป็น RPM
    Serial.print("RPM: ");
    Serial.println(rpm);
    pulseCount = 0;
    lastTime = currentTime;
  }
}

void countPulse() {
  pulseCount++;
}
