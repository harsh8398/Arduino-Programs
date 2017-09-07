/************************************************************************
 * Title  : Receive serially data 0 t0 9 and display on LCD             *
 * Date   : 03/09/2017                                                  *
 * Author : Harsh Patel                                                 *
 * ID No  : 15it077                                                     *
 * E-mail : 15it077@charusat.edu.in                                     *
 ************************************************************************/
#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Received data...");
}

void loop() {
  if(Serial.available()) {
    char data = Serial.read();
    if(isdigit(data)) {
      lcd.setCursor(0, 1);
      lcd.print(int(data - '0'));
    }
  }
}
