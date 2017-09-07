/***********************************************************************
 * Title  : Combine all above in single program                        *
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
  // run five times
  for(int i = 0; i < 5; i++) {
    EightOnOff();
  }
  //clear PORT after running one pattern
  PORTD = 0x00;
  delay(500);
  
  for(int i = 0; i < 5; i++) {
    FourOnOff();
  }
  PORTD = 0x00;
  delay(500);

  for(int i = 0; i < 5; i++) {
    AlternateLEDs();
  }
  PORTD = 0x00;
  delay(500);
  
  for(int i = 0; i < 5; i++) {
    LeftRightSeries();
  }
  PORTD = 0x00;
  delay(500);
}
