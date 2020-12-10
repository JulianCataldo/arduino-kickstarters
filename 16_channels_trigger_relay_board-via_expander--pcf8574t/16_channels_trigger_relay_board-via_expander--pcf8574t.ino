

#include <Wire.h>

#define PIN1  0B00000001  // binary value of the first pin
#define PIN2  0B00000010  // binary value of the second pin
#define PIN3  0B00000100  // third pin
#define PIN4  0B00001000  // fourth pin
#define PIN5  0B00010000  // fifth pin
#define PIN6  0B00100000  // sixth pin
#define PIN7  0B01000000  // seventh pin
#define PIN8  0B10000000  // eighth pin


void setup() {
Wire.begin();
  Serial.begin(9600);
pinMode(2,INPUT);
}

void loop() {
Wire.beginTransmission(0x27);
Wire.write(PIN1 );

Wire.endTransmission();

//Serial.println(digitalRead(2));

delay(250);

Wire.beginTransmission(0x27);
Wire.write(PIN3);

Wire.endTransmission();

//Serial.println(digitalRead(2));

delay(150);
}
