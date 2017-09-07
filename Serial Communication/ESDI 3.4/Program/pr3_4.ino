/****************************************************************************
 * Title  : Interface switch and to following:                              *
 *          SW1 : when press, transmit "Good Morning "                      *
 *          SW1 : when open, transmit "Bad Morning "                        *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#define SW1 9

void setup() {
  pinMode(SW1, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(SW1)) {
    Serial.println("Good Morning");
  } else {
    Serial.println("Bad Morning");
  }
}

