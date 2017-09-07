/************************************************************************
 * Title  : Display 00 to 99 on segment                                 *
 * Date   : 03/09/2017                                                  *
 * Author : Harsh Patel                                                 *
 * ID No  : 15it077                                                     *
 * E-mail : 15it077@charusat.edu.in                                     *
 ************************************************************************/
int num[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
int cnt = 0;

void showDigit(int digit);

void setup() {
  for(int i=0;i<10;i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  showDigit(cnt);
  cnt++;
  if(cnt>99) cnt = 0;
}

void showDigit(int digit) {
  for(int i = 0; i < 100; i++) {
    PORTB = 0x02;
    PORTD = num[digit/10];
    delay(5);
    PORTB = 0x01;
    PORTD = num[digit%10];
    delay(5);
  }
}

