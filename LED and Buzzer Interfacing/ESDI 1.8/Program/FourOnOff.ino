void FourOnOff() {
  // turn first 4 LEDs ON and last 4 OFF
  PORTD = 0b00001111;
  delay(1000);
  // turn frst 4 LEDs OFF and last 4 ON
  PORTD = 0b11110000;
  delay(1000);
}

