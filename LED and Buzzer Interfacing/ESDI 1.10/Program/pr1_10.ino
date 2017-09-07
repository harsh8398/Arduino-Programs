/**********************************************
 * Title  : Sound the buzzer every 1 second.  *
 * Date   : 03/09/2017                        *
 * Author : Harsh Patel                       *
 * ID No  : 15it077                           *
 * E-mail : 15it077@charusat.edu.in           *
 **********************************************/
#define BuzzerPin 9
void setup() {
  pinMode(BuzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(BuzzerPin, HIGH);
  delay(1000);
  digitalWrite(BuzzerPin, LOW);
  delay(1000);
}
