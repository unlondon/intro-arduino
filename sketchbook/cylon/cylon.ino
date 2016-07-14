int delay_ms;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  for (int i = 4; i <= 7; i++) {
    delay_ms = analogRead(A0);
    digitalWrite(i - 1, LOW);
    digitalWrite(i, HIGH);
    delay(delay_ms);
  }
  for (int i = 6; i >= 3; i--) {
    delay_ms = analogRead(A0);
    digitalWrite(i + 1, LOW);
    digitalWrite(i, HIGH);
    delay(delay_ms);
  }
}
