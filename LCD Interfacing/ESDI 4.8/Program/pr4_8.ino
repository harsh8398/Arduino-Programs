/************************************************************************
 * Title  : Set the time using four switch and display the clock on LCD *
 *          SW1 : when press, increment 1 digit                         *
 *          SW2 : when press, decrement 1 digit                         *
 *          SW3 : when press, display set time and start the clock      *
 *          SW4 : when press, reset the clock                           *
 * Date   : 03/09/2017                                                  *
 * Author : Harsh Patel                                                 *
 * ID No  : 15it077                                                     *
 * E-mail : 15it077@charusat.edu.in                                     *
 ************************************************************************/
#include<LiquidCrystal.h>
#define SETUP 14
#define START 15
#define UP 16
#define DOWN 17

long timer;
int h = 10, m = 10, s = 0, setCnt = 0;
char mode = 's';     // 's' -> setup mode, 'r' -> running mode

void showTime(int h, int m, int s);
void setupMode();
void runningMode(char mode = 'r');
void resetMethod();
void startMethod();

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  for(int i = 14; i < 18; i++) {
    pinMode(i, INPUT);
  }
  lcd.begin(16, 2);
  timer = millis();
}

void loop() {
  if(digitalRead(SETUP)) {
    if(setCnt<2) setCnt++;
    else setCnt = 0;
    delay(300);
  } else if(digitalRead(START)) {
    setCnt = 0;
    delay(300);
  }
  switch(setCnt) {
    case 0:
      runningMode();
      break;
    case 1:
      setupMode();
      break;
    case 2:
      setupMode();
      break;
  }
}


void showTime(int h, int m, int s) {
  lcd.print(h/10);
  lcd.print(h%10);
  lcd.print(" : ");
  lcd.print(m/10);
  lcd.print(m%10);
  lcd.print(" : ");
  lcd.print(s/10);
  lcd.print(s%10);
}

void runningMode(char mode = 'r') {
  if(millis()-timer>1000) {
    timer = millis();
    lcd.clear();
    lcd.setCursor(0, 0);
//    if(mode == 's') {
//      if(setCnt == 1) lcd.print("+|-");
//      else if(setCnt == 2) lcd.print("     +|-");
//      lcd.setCursor(0, 1);
//      showTime(h, m, s);
//    }
//    else showTime(h,m,s);
    if(mode == 's') {
      lcd.print("set time");
      lcd.setCursor(0, 1);
      showTime(h,m,s);
    }
    else showTime(h,m,s);
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
}

void setupMode() {
  if(digitalRead(UP)) {
    if(setCnt == 1) {
      if(h<23) h++;
      else h = 0;
    }
    else {
      if(m<59) m++;
      else m = 0;
    }
    delay(300);
  }
  else if(digitalRead(DOWN)) {
    if(setCnt == 1) {
      if(h>0) h--;
      else h = 23;
    }
    else {
      if(m>0) m--;
      else m = 59;
    }
    delay(300);
  }
  runningMode('s');
}
