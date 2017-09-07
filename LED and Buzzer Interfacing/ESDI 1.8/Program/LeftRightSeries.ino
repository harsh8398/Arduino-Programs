void LeftRightSeries() {
  // left series pattern
  for(int  i = 7; i >= 0; i--) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
  }
  // right series pattern
  for(int  i = 0; i < 8; i++) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
  }
}

