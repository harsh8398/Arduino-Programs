/****************************************************************************
 * Title  : Transmit and receive the data in serially                       *
 * Date   : 03/09/2017                                                      *
 * Author : Harsh Patel                                                     *
 * ID No  : 15it077                                                         *
 * E-mail : 15it077@charusat.edu.in                                         *
 ****************************************************************************/
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  Serial.println("Send data...");
  mySerial.begin(9600);
  mySerial.println("Receiving...");
}

void loop() {
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}

