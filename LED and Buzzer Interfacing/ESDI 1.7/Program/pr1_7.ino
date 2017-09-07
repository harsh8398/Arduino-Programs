/***********************************************************************
 * Title  : Interface 8 LEDs. Generate left and right series patterns. *
 * Date   : 03/09/2017                                                 *
 * Author : Harsh Patel                                                *
 * ID No  : 15it077                                                    *
 * E-mail : 15it077@charusat.edu.in                                    *
 ***********************************************************************/
void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
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
