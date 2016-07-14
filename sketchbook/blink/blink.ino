#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);   // turn on LED
  delay(1000);              // wait for a second
  digitalWrite(LED, LOW);    // turn the off LED
  delay(1000);
}
