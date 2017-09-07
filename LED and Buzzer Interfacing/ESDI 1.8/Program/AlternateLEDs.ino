void AlternateLEDs() {
  for(int  i = 0; i < 8; i++) {
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
  }
}

