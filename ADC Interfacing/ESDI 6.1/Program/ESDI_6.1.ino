/****************************************************************************
 * Title  : Using Trim Pot of 5K set the voltage range between 0 V to 5V.   *
 *          Monitor value of voltage & transmit it serially.                *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
float vout;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  // modify range from 0-1023 to 0-5
  vout = (analogRead(A0) / 1023.0) * 5.0;
  Serial.println(vout);

}
