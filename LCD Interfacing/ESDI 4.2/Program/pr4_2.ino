/***********************************************************************
 * Title  : Display 00 to 99 on LCD                                    *
 * Date   : 03/09/2017                                                 *
 * Author : Harsh Patel                                                *
 * ID No  : 15it077                                                    *
 * E-mail : 15it077@charusat.edu.in                                    *
 ***********************************************************************/
#include<LiquidCrystal.h>
int cnt = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(cnt++);
  delay(500);
  lcd.clear();
  if(cnt > 99) cnt = 0;
}
