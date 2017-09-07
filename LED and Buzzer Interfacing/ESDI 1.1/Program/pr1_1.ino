/**********************************************
 * Title  : Flash/toggle/on off single LED.   *
 * Date   : 03/09/2017                        *
 * Author : Harsh Patel                       *
 * ID No  : 15it077                           *
 * E-mail : 15it077@charusat.edu.in           *
 **********************************************/
#define LEDpin 13
void setup() {
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  digitalWrite(LEDpin, HIGH);
  delay(1000);
  digitalWrite(LEDpin, LOW);
  delay(1000);
}
