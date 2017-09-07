float vout;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A2,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  vout=analogRead(A2);
  //vout=vout-1023;
  if(vout>1022)
    {
      Serial.println("Device on!");
      Serial.print(vout);
      tone(13,2000);
    }
  else
  {
    Serial.println("Device off!");
    Serial.print(vout);
    noTone(13);  
  }
}
