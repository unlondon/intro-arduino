#define BUTTON 2
#define BUZZER 8
#define WINNER 5

int delay_ms;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void buzz(int ms) {
  digitalWrite(BUZZER, HIGH);
  delay(ms);
  digitalWrite(BUZZER, LOW);
}

void set_all_leds(int state) {
  for (int i = 3; i <= 7; i++) {
    digitalWrite(i, state);
  }
}

void do_winner(void) {
  set_all_leds(HIGH);
  buzz(100);
  delay(100);
  buzz(100);
  set_all_leds(LOW);
}

void do_loser(void) {
  buzz(500);
}

void check_delay(int cur_led, int delay_ms) {
  unsigned long start = millis();
  while (millis() < start+delay_ms) {
    if (digitalRead(BUTTON) == LOW) {
      if (cur_led == WINNER) {
        do_winner();
      } else {
        while (digitalRead(BUTTON) == LOW) {
          do_loser();
        }
      }
    }
  }
}

void loop() {
  for (int i = 4; i <= 7; i++) {
    delay_ms = analogRead(A0);
    digitalWrite(i - 1, LOW);
    digitalWrite(i, HIGH);
    check_delay(i, delay_ms);
  }
  for (int i = 6; i >= 3; i--) {
    delay_ms = analogRead(A0);
    digitalWrite(i + 1, LOW);
    digitalWrite(i, HIGH);
    check_delay(i, delay_ms);
  }
}
