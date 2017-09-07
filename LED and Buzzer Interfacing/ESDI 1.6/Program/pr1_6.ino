/**************************************************************
 * Title  : Interface 8 LEDs. Generate right series patterns. *
 * Date   : 03/09/2017                                        *
 * Author : Harsh Patel                                       *
 * ID No  : 15it077                                           *
 * E-mail : 15it077@charusat.edu.in                           *
 **************************************************************/
void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // right series pattern
  for(int  i = 0; i < 8; i++) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
  }
}
