/****************************************************************************
 * Title  : Enter password and password display on lcd                      *
 *          if password rigESDI then door open(motor rotate clockwise);     *
 *          otherwise close                                                 *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#include <Keypad.h>
#include <LiquidCrystal.h>

#define MP 13
#define MN 12

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
String buffr = ""; // buffr stores user input when entering password

String passwd = "1234"; // passwd stores passwd for unlocking

int top = 0; // top is end of the buffr
int flagPasswd = 1; // used to know if program is being run first time

//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'7', '8', '9', 'E'}, /* E -> Erase */
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'C', '0', 'K', 'S'} /* S -> OK(Next or Enter). */
};
byte rowPins[ROWS] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd(14, 15, 16, 17, 18, 19);

void setup() {
  pinMode(MP, OUTPUT);
  pinMode(MN, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  char customKey = customKeypad.getKey();
  if (flagPasswd) {
    clearBuffr();
    printPasswd();
    flagPasswd = 0;
  }
  switch (customKey) {
    case 'E':
      buffr.remove(--top);
      printPasswd();
      break;
    case 'S':
      checkPasswd();
      clearBuffr();
      printPasswd();
      break;
    case '0' ... '9':
      buffr += customKey;
      top++;
      printPasswd();
      break;
  }
}

void checkPasswd() {
  if (passwd == buffr) {
    passwdCorrect();
  }
  else {
    passwdIncorrect();
  }
}

void passwdCorrect() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Door is opening...");
  doorOpen();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome!");
  lcd.setCursor(0, 1);
  lcd.print("Door is open.");
  while(1);
}

void passwdIncorrect() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Incorrect!");
  lcd.setCursor(0, 1);
  lcd.print("Door is locked.");
  delay(2000);
}

void printPasswd() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter passcode: ");
  if (top) {
    for (int i = 0; i < top; i++) {
      lcd.setCursor(i, 1);
      lcd.print("*");
    }
  }
}

void doorOpen() {
  // rotate motor clockwise to open the door
  digitalWrite(MP, HIGH);
  digitalWrite(MN, LOW);
  delay(3000);
  digitalWrite(MP, LOW);
}

void clearBuffr() {
  buffr = String("");
  top = 0;
}
