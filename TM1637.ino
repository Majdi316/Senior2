#include <TM1637Display.h> //libary
// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3
//define the data
const uint8_t SEG_DONE[] = {
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F ,           // 0
  SEG_B | SEG_C | SEG_D | SEG_F | SEG_G,                   // Y
  SEG_A | SEG_B | SEG_D | SEG_E | SEG_G,           // z
  SEG_C | SEG_E | SEG_G                                    // n

  };
  TM1637Display display(CLK, DIO);//object from libary tm1637display
  
void setup() {
 display.setBrightness(7);// 0-7 display light
}

void loop() {
  // put your main code here, to run repeatedly:
display.setSegments(SEG_DONE);
delay(1500);// in milliseconds
display.clear();
delay(1000);
display.showNumberDec(30, false,2,1); // Expect: _301 example an number
  delay(1000);
  display.clear();
delay(1000);
display.showNumberHexEx(0xafff);          // Expect: __2C example an hexa digit 
  delay(1000);
  
  display.clear();
 delay(1000);
}
