#define LED 13
void setup() {
  pinMode(LED, OUTPUT);
}
void loop() {
  digitalWrite(LED, HIGH);
  delay(analogRead(A0));
  digitalWrite(LED, LOW);
  delay(analogRead(A0));
}

void buzz(int ms) {
  return;
}

