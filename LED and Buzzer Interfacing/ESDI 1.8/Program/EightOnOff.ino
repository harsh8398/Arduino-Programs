void EightOnOff() {
  // turn all 8 LEDs ON
  PORTD = 0b11111111;
  delay(1000);
  // turn all 8 LEDs OFF
  PORTD = 0b00000000;
  delay(1000);
}

