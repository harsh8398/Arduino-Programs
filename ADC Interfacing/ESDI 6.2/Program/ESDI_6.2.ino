/****************************************************************************
 * Title  : Using Trim Pot of 5K set the voltage range between 0 V to 5V.   *
 *          Monitor value of voltage &Display on LCD.                       *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float vout;

void setup() {
  pinMode(A0,INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Voltage[0-5v]:");
}

void loop() {
  // modify range from 0-1023 to 0-5
  vout = (analogRead(A0) / 1023.0) * 5.0;

  lcd.setCursor(0, 1);
  lcd.print(vout);
  lcd.print(" V");
}
