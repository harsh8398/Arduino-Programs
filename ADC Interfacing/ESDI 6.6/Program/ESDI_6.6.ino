/****************************************************************************
 * Title  : Light fall on LDR and display value on lcd.                     *
 *          if value < 50,device off serially print and buzzer off          *
 *          if value > 50,device on serially print and buzzer on            *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#define ldrIN A0
#define BuzzerPin 2

float ldrReading;

void setup() {
  pinMode(ldrIN, INPUT);
  pinMode(BuzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrReading = analogRead(ldrIN);
  if(ldrReading > 50) {
    Serial.println("device on");
    ringBuzzer();
  } else {
     Serial.println("device off");
  }
}

void ringBuzzer() {
  digitalWrite(BuzzerPin, HIGH);
  delay(1000);
  digitalWrite(BuzzerPin, LOW);
  delay(1000);
}

