/*
  SerialLCD Library - Hello World
 
 Demonstrates the use a 16x2 LCD SerialLCD driver from Seeedstudio.
 
 This sketch prints "Hello, Seeeduino!" to the LCD
 and shows the time.
 
 Library originally added 16 Dec. 2010
 by Jimbo.we 
 http://www.seeedstudio.com
 */

// include the library code:
#include <SerialLCD.h>
#include <SoftwareSerial.h> //this is a must

// initialize the library
SerialLCD slcd(11,12);//this is a must, assign soft serial pins
const int pingPin = 4;

void setup() {
  // set up
  slcd.begin();
  // Print a message to the LCD.
  slcd.print("he");
}

void loop() {
  long duration, cm;
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  slcd.setCursor(0, 1);
  // print the number of seconds since reset:
  slcd.print(millis()/1000,DEC);
pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
    slcd.print(cm);
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
