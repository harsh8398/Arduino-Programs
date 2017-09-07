/****************************************************************************
 * Title  : Display the clock(HH : MM:SS) on segment                        *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
int num1[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
int num2[10] = {0xbf, 0x86, 0xdb, 0xcf, 0xe6, 0xed, 0xfd, 0x87, 0xff, 0xef};
int digit[6] = {0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe};
long timer;
int h = 23, m = 58, s = 55;

void showTime(int h, int m, int s);

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
      h++;
      if(h >= 24) {
        h = 0;
      }
    }
  }
  showTime(h,m,s);
}

void showTime(int h, int m, int s) {
  PORTB = digit[0];
  PORTD = num1[h/10];
  delay(1);
  PORTB = digit[1];
  PORTD = num2[h%10];
  delay(1);
  PORTB = digit[2];
  PORTD = num1[m/10];
  delay(1);
  PORTB = digit[3];
  PORTD = num2[m%10];
  delay(1);
  PORTB = digit[4];
  PORTD = num1[s/10];
  delay(1);
  PORTB = digit[5];
  PORTD = num1[s%10];
  delay(1);
}

