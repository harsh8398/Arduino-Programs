/************************************************************************
 * Title  : Display animation using the custom character on LCD         *
 *          Ex.: "Hello World"                                          *
 * Date   : 03/09/2017                                                  *
 * Author : Harsh Patel                                                 *
 * ID No  : 15it077                                                     *
 * E-mail : 15it077@charusat.edu.in                                     *
 ************************************************************************/
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte arrow[8] = {
  0b00000,
  0b00100,
  0b00010,
  0b11111,
  0b00010,
  0b00100,
  0b00000,
  0b00000
};

byte fall[8] = {
  0b00000,
  0b00001,
  0b00111,
  0b01110,
  0b11100,
  0b01110,
  0b00111,
  0b00001
};


void setup() {
  lcd.begin(16, 2);

  // create a new character
  lcd.createChar(0, heart);
  lcd.createChar(1, arrow);
  lcd.createChar(2, fall);
  
}

void loop() {
 
  
  for(int i=0;i<=8;i++)
  {
    lcd.setCursor(8,0);
    lcd.write(byte(0));
    lcd.setCursor(i,0);
    lcd.write(byte(1));
    delay(100);
    lcd.clear();
  }
  lcd.setCursor(9,1);
  lcd.write(byte(2));
  delay(500);
  
  }
