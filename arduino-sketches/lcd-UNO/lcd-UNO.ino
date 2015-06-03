#include <SerialLCD.h>
#include <SoftwareSerial.h> //this is a must
#include <math.h>
// initialize the library
SerialLCD slcd(11,12);//this is a must, assign soft serial pins

const int tempPin = 0; 

void setup() {
  // set up
  slcd.begin();
  // Print a message to the LCD.
  slcd.print("Temperature is:");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  slcd.setCursor(0, 1);
  // print the number of seconds since reset:
//  float TT = readTemp();
  SLCDprintFloat( readTemp() ,1);
  slcd.print(" Celsius");  
  delay(1000);
}
void SLCDprintFloat(double number, uint8_t digits) 
{ 
  // Handle negative numbers
  if (number < 0.0)
  {
     slcd.print('-');
     number = -number;
  }

  // Round correctly so that slcd.print(1.999, 2) prints as "2.00"
  double rounding = 0.5;
  for (uint8_t i=0; i<digits; ++i)
    rounding /= 10.0;
  
  number += rounding;

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;
  float remainder = number - (float)int_part;
  slcd.print(int_part , DEC); // base DEC

  // Print the decimal point, but only if there are digits beyond
  if (digits > 0)
    slcd.print("."); 

  // Extract digits from the remainder one at a time
  while (digits-- > 0)
  {
    remainder *= 10.0;
    float toPrint = float(remainder);
    slcd.print(toPrint , DEC);//base DEC
    remainder -= toPrint; 
  } 
}

float readTemp()
{
  const int B=3975; 
  double TEMP;
  int sensorValue = analogRead( tempPin );
  float Rsensor;
  Rsensor=(float)(1023-sensorValue)*10000/sensorValue;
  TEMP=1/(log(Rsensor/10000)/B+1/298.15)-273.15;
  return TEMP;
}

