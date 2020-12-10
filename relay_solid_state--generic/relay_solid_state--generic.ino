void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(150);                       // wait for a second
  digitalWrite(2, HIGH);    // turn the LED off by making the voltage LOW
  delay(7500);                       // wait for a second
}
