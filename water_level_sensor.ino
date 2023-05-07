int readPin = A0;
int readValue; //0-1023
void setup() {
  // put your setup code here, to run once:
pinMode(readPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
readValue=analogRead(readPin);
Serial.println(readValue);
delay(1000);
}
