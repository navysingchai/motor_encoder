const int motorPin = 9;

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  analogWrite(motorPin, 128);  // 0 - 255 (128 = ~50% speed)
}
