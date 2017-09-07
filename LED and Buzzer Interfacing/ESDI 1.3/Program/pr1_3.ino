/********************************************************************
 * Title  : Interface 8 LEDs. Out of Four LED ON and Four LED OFF.  *
 * Date   : 03/09/2017                                              *
 * Author : Harsh Patel                                             *
 * ID No  : 15it077                                                 *
 * E-mail : 15it077@charusat.edu.in                                 *
 ********************************************************************/
void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // turn first 4 LEDs ON and last 4 OFF
  PORTD = 0b00001111;
  delay(1000);
  // turn frst 4 LEDs OFF and last 4 ON
  PORTD = 0b11110000;
  delay(1000);
}
