/***********************************************************************
 * Title  : Display the string on LCDEx.: "Hello World"                *
 * Date   : 03/09/2017                                                 *
 * Author : Harsh Patel                                                *
 * ID No  : 15it077                                                    *
 * E-mail : 15it077@charusat.edu.in                                    *
 ***********************************************************************/
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hello World!");
}

void loop() {
}
