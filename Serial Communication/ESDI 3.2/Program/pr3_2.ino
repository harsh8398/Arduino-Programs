/****************************************************************************
 * Title  : Receive the data between 0 to 9 serially and display on LED     *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
void setup() {
  for(int i = 8; i < 12; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    if(isdigit(data)) PORTB = int(data - '0');
  }
}

