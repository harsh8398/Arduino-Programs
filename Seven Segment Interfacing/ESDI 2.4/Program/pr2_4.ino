/************************************************************************
 * Title  : Display 0000 to 9999 on segment                             *
 * Date   : 03/09/2017                                                  *
 * Author : Harsh Patel                                                 *
 * ID No  : 15it077                                                     *
 * E-mail : 15it077@charusat.edu.in                                     *
 ************************************************************************/
int num[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
int cnt = 0;

void showDigit(int digit);

void setup() {
  for(int i=0;i<12;i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  showDigit(cnt);
  cnt++;
  if(cnt>9999) cnt = 0;
}

void showDigit(int digit) {
  for(int i = 0; i < 250; i++) {
    PORTB = 0x0E;
    PORTD = num[digit/1000];
    delay(1);
    PORTB = 0x0D;
    PORTD = num[(digit%1000)/100];
    delay(1);
    PORTB = 0x0B;
    PORTD = num[(digit%100)/10];
    delay(1);
    PORTB = 0x07;
    PORTD = num[digit%10];
    delay(1);
  }
}
