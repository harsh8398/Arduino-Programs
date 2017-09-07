/***********************************************************************
 * Title  : Interface 4 push button & do following:                    *
 *          SW1 : when press, display 0 to 9                           *
 *          SW2 : when press, display 00 to 99                         *
 *          SW3 : when press, display 000 to 999                       *
 *          SW4 : when press, display 0000 to 9999                     *
 * Date   : 03/09/2017                                                 *
 * Author : Harsh Patel                                                *
 * ID No  : 15it077                                                    *
 * E-mail : 15it077@charusat.edu.in                                    *
 ***********************************************************************/
#include<LiquidCrystal.h>
int cnt = 0, currentSwitch = 1, loopCnt = 0;
int SW[] = {A0, A1, A2, A3};

void showDigits(int);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  for(int i = 0; i < 4; i++) {
    pinMode(SW[i], INPUT);
  }
  lcd.begin(16, 2);
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
  loopCnt++;
  if(loopCnt > 10000) {
    lcd.clear();
    lcd.setCursor(0, 0);
    
    lcd.print("0-");
    lcd.print(limit);
    lcd.print(": ");
    lcd.print(cnt);
    
    loopCnt = 0;
    cnt++;
  }
  if(cnt > limit) cnt = 0;
}
