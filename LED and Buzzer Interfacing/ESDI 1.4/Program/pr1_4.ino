/**********************************************
 * Title  : Alternate ON OFF eigESDI LED.     *
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
  for(int  i = 0; i < 8; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
}
