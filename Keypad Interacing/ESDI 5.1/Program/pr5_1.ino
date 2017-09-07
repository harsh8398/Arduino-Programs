/****************************************************************************
 * Title  : Press any key from 4*4 keypad and display on lcd.                *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal lcd(14, 15, 16, 17, 18, 19);

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Key Pressed:");
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    lcd.setCursor(0, 1);
    lcd.print(customKey);
  }
}
