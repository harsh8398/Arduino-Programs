/************************************************************************
 * Title  : Multiplexed 4 7-segment & do following:                     *
 *          If SW1 press, display 0 to 9                                *
 *          If SW2 press, display 00 to 99                              *
 *          If SW3 press, display 000 to 999                            *
 *          If SW4 press, display 0000 to 9999                          *
 * Date   : 03/09/2017                                                  *
 * Author : Harsh Patel                                                 *
 * ID No  : 15it077                                                     *
 * E-mail : 15it077@charusat.edu.in                                     *
 ************************************************************************/
int num[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
int cnt = 0, currentSwitch = 1, loopcnt = 0;
int SW[4] = {14, 15, 16, 17};

void showDigits();

void setup() {
  for(int i=0;i<12;i++) {
    pinMode(i, OUTPUT);
  }
  for(int i=14;i<18;i++) {
    pinMode(i, INPUT);
  }
}

void loop() {
  for(int i = 0; i < 4; i++) {
    if(digitalRead(SW[i]) && (i+1) != currentSwitch) {
      cnt = 0;
      currentSwitch = i+1;
      break;
    }
  }
  switch(currentSwitch) {
    case 1:
      showDigits(9);
      break;
    case 2:
      showDigits(99);
      break;
    case 3:
      showDigits(999);
      break;
    case 4:
      showDigits(9999);
      break;
  }
}

void showDigits(int limit) {
  PORTB = 0x0e;
  PORTD = num[cnt/1000];
  delay(1);
  PORTB = 0x0d;
  PORTD = num[(cnt%1000)/100];
  delay(1);
  PORTB = 0x0b;
  PORTD = num[(cnt%100)/10];
  delay(1);
  PORTB = 0x07;
  PORTD = num[cnt%10];
  delay(1);

  // for removing flickering of digits and shows each digit for approx. 1 sec
  loopcnt++;
  if(loopcnt > 250) {
    cnt++;
    loopcnt = 0;
  }
  if(cnt > limit) cnt = 0;
}

