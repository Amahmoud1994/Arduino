/***************************************************************************/        
// Function: Measure the distance to obstacles in front and display the
//                         result on seeedstudio serialLcd. Make sure you installed the
//                         serialLCD, SoftwareSerial and Ultrasonic library.        
//        Hardware: Grove - Ultrasonic Ranger, Grove - Serial LCD
//        Arduino IDE: Arduino-1.0
//        Author:         LG                
//        Date:          Jan 17,2013
//        Version: v1.0 modified by FrankieChu
//        by www.seeedstudio.com

/*****************************************************************************/

//#include <SoftwareSerial.h>
//#include <SerialLCD.h>
#include "Ultrasonic.h"

//SerialLCD slcd(11,12);
Ultrasonic ultrasonic(4);
void setup()
{
   Serial.begin(9600);
}
void loop()
{
        long RangeInCentimeters;
        RangeInCentimeters = ultrasonic.MeasureInCentimeters();
        Serial.println(RangeInCentimeters);
        delay(150);
        
}
