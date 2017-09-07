/************************************************************************
 * Title  : Display the clock(HH : MM : SS) on LCD                      *
 * Date   : 03/09/2017                                                  *
 * Author : Harsh Patel                                                 *
 * ID No  : 15it077                                                     *
 * E-mail : 15it077@charusat.edu.in                                     *
 ************************************************************************/
#include<LiquidCrystal.h>

long timer;
int h = 23, m = 59, s = 55;

void showTime(int h, int m, int s);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2);
  timer = millis();
}

void loop() {
  if(millis()-timer>1000) {
    timer = millis();
    showTime(h,m,s);
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

void showTime(int h, int m, int s) {
  lcd.clear();
  lcd.setCursor(0, 0);
  
  lcd.print(h/10);
  lcd.print(h%10);
  lcd.print(" : ");
  lcd.print(m/10);
  lcd.print(m%10);
  lcd.print(" : ");
  lcd.print(s/10);
  lcd.print(s%10);
}
