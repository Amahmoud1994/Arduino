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

#include <SoftwareSerial.h>
#include <SerialLCD.h>
#include "Ultrasonic.h"

SerialLCD slcd(11,12);
Ultrasonic ultrasonic(7);
void setup()
{
   slcd.begin();
}
void loop()
{
        long RangeInCentimeters;
        RangeInCentimeters = ultrasonic.MeasureInCentimeters();
        delay(150);
        slcd.clear();
        slcd.setCursor(0,0);
        slcd.print("The distance:");
        slcd.setCursor(0,1) ;
        slcd.print(RangeInCentimeters,DEC);
        slcd.setCursor(5,1) ;
        slcd.print("cm");
}
