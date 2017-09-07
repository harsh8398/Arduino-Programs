/**********************************************
 * Title  : Flash/toggle/on off eight LEDs.   *
 * Date   : 03/09/2017                        *
 * Author : Harsh Patel                       *
 * ID No  : 15it077                           *
 * E-mail : 15it077@charusat.edu.in           *
 **********************************************/
void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // turn all 8 LEDs ON
  PORTD = 0b11111111;
  delay(1000);
  // turn all 8 LEDs OFF
  PORTD = 0b00000000;
  delay(1000);
}
