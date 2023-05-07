#include <TM1637Display.h>
#define CLK 2
#define DIO 3
int readPin = A0;
int readValue;
const uint8_t SEG_LOW[] = {
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_D | SEG_E | SEG_F,                           //L
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_D | SEG_E                            // U
  };
const uint8_t SEG_HIGH[] = {
  SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,           // H
  SEG_E | SEG_F,                                   // I
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_F | SEG_G,   // G
  SEG_B | SEG_C | SEG_E | SEG_F | SEG_G           // H
  };
const uint8_t SEG_NIDD[] = {
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_E | SEG_F,                                   // I
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,            // D
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G            // D
  };
TM1637Display display(CLK, DIO);

void setup() {
  // put your setup code here, to run once:
pinMode(readPin,INPUT);
display.setBrightness(1);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
readValue=analogRead(readPin);
if(readValue <200)
{
  display.clear();
  delay(500);
  display.setSegments(SEG_LOW);
  Serial.println(readValue);
  delay(2000);  
}
else if((readValue >201)&&(readValue <450))
{
  display.clear();
  delay(500);
  display.setSegments(SEG_NIDD);
  Serial.println(readValue);
  delay(2000);  
} 
else if(readValue >451)
{
  display.clear();
  delay(500);
  display.setSegments(SEG_HIGH);
  Serial.println(readValue);
  delay(2000);   
} 
}
