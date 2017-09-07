/************************************************************************
 * Title  : Display 0 to 9 on segment                                   *
 * Date   : 03/09/2017                                                  *
 * Author : Harsh Patel                                                 *
 * ID No  : 15it077                                                     *
 * E-mail : 15it077@charusat.edu.in                                     *
 ************************************************************************/
int num[10] = {0x7e, 0x30, 0x6d, 0x79, 0x33, 0x5b, 0x5f, 0x70, 0x7f, 0x7b};
void setup() {
  for(int i=0;i<7;i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < 10; i++) {
    PORTD = num[i];
    delay(500);
  }
}
