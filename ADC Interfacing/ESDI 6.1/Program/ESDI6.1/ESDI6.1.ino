float vout;
void setup() {
  // put your setup code here, to run once:
  pinMode(A2,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  vout=analogRead(A2);
  Serial.println(vout);

}
