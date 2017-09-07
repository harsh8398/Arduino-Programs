/****************************************************************************
 * Title  : Display the clock(MM : SS) on segment                           *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
int num[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
int digit[6] = {0xf7, 0xfb, 0xfd, 0xfe};
long timer;
int m = 59, s = 55;

void showTime(int m, int s);

void setup() {
  for(int i = 0; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  timer = millis();
}

void loop() {
  if(millis()-timer>1000) {
    timer = millis();
    s++;
  }
  if(s >= 60) {
    s = 0;
    m++;
    if(m >= 60) {
      m = 0;
    }
  }
  showTime(m,s);
}

void showTime(int m, int s) {
  PORTB = digit[0];
  PORTD = num[m/10];
  delay(1);
  PORTB = digit[1];
  PORTD = num[m%10];
  delay(1);
  PORTB = digit[2];
  PORTD = num[s/10];
  delay(1);
  PORTB = digit[3];
  PORTD = num[s%10];
  delay(1);
}

