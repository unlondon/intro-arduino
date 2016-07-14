#define BUZZER 8
#define BUTTON 2

int button_state;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(BUZZER, OUTPUT);
}
void buzz(int ms) {
  digitalWrite(BUZZER, HIGH);
  delay(ms);
  digitalWrite(BUZZER, LOW);
}

void loop() {
  button_state = digitalRead(BUTTON);
  if (button_state == LOW) {
    buzz(100);
  }
}

