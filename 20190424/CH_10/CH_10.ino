int high_Byte = 0;
int low_Byte = 0;
int distance = 0;
int ledPin = 9;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  Serial.write("U");
  delay(500);
  if (Serial.available() == 2) {
    high_Byte = Serial.read();
    low_Byte = Serial.read();
    distance = high_Byte * 256 + low_Byte;
    Serial.print(distance);
    Serial.println("mm");
    if (distance < 30) 
    {
       digitalWrite(ledPin, HIGH);
       delay(2000);
    }   
     digitalWrite(ledPin, LOW);

   delay(1000);
  }
}

