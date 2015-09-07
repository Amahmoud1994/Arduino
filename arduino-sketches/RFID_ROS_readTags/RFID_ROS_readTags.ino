/***************************************************************************
 * RFIDuino Hello World 
 *
 * This demo uses the RFIDuino sheild, a Geekduino (or other Arduino Board)
 * and the RFIDuino library to scan for a tag. Once a tag is read, the ID of
 * the tag is stored as an array of 5 byte-sized numbers. This array of numbers 
 * represents the ID. After a sucessful read, these 6 numbers will be sent over
 * the Arduino's Serial Port. This demo can also be used to send data to
 * XBee modules.
 *
 * The RFIDuino library is compatible with both versions of the RFIDuino shield
 * (1.1 and 1.2), but the user must initialize the library correctly. See 
 * 'HARDWARE VERSION' instructions near the beginning of the code.
 *
 * The RFIDuino Shield is designed to be used with 125khz EM4100 family tags. 
 * This includes any of the EM4102 tags sold by Trossen Robotics/ RobotGeek. 
 * The RFIDuino shield may not work with tags outside the EM4100 family
 *
 *
 * Links
 *    RFIDUino Getting Started Guide
 *      http://learn.robotgeek.com/getting-started/41-rfiduino/142-rfiduino-getting-started-guide.html
 *    RFIDUino Library Documentation
 *      http://learn.robotgeek.com/41-rfiduino/144-rfiduino-library-documentation.html
 *    RFIDUino Shield Product Page
 *      http://www.robotgeek.com/rfiduino
 *  
 *
 * User Output pins
 *    myRFIDuino.led1 - Red LED
 *    myRFIDuino.led2 - Green LE
 *    myRFIDuino.buzzer - Buzzer
 *
 ***************************************************************************/
#include <ros.h>
#include <std_msgs/String.h>
#include <RFIDuino.h> //include the RFIDuino Library

//#define SERIAL_PORT Serial      //Serial port definition for Geekduino, Arduino Uno, and most Arduino Boards
//#define SERIAL_PORT Serial1   //Serial port defintion for Arduino Leonardo and other ATmega32u4 based boards

/***************
* HARDWARE VERSION - MAKE SURE YOU HAVE SET THE CORRECT HARDWARE VERSION BELOW
* Version 1.1 has a 4-pin antenna port and no version marking
* Version 1.2 has a 2-pin antenna port and is marked 'Rev 1.2'
*****************/
RFIDuino myRFIDuino(1.1);     //initialize an RFIDuino object for hardware version 1.1
//RFIDuino myRFIDuino(1.2);   //initialize an RFIDuino object for hardware version 1.2
ros::NodeHandle  nodeHandler;
std_msgs::String str_msg;
char tagWord[8];
String tagStr;
ros::Publisher pub_tag("/tagRead", &str_msg);

byte tagData[5]; //Holds the ID numbers from the tag  

void setup()
{
  nodeHandler.initNode();
  nodeHandler.advertise(pub_tag); 
  //Serial.begin(9600);
}

void loop()
{   
  //scan for a tag - if a tag is sucesfully scanned, return a 'true' and proceed
  if(myRFIDuino.scanForTag(tagData) == true)
  {
    /*
  //  SERIAL_PORT.print("RFID Tag ID:"); //print a header to the Serial port.
    //loop through the byte array
    for(int n=0;n<5;n++)
    {
    //  SERIAL_PORT.print(tagData[n],DEC);  //print the byte in Decimal format
     
    }
    //SERIAL_PORT.print("\n\r");//return character for next line
   */          
    digitalWrite(myRFIDuino.led2,HIGH);     //turn green LED on
    digitalWrite(myRFIDuino.buzzer, HIGH);   //turn the buzzer on
    delay(1000);                             //wait for 1 second
    digitalWrite(myRFIDuino.buzzer, LOW);    //turn the buzzer off
    digitalWrite(myRFIDuino.led2,LOW);      //turn the green LED off

      tagStr = String(tagData[0]);
      tagStr = tagStr + String(tagData[1]);
      tagStr = tagStr + String(tagData[2]);
      tagStr = tagStr + String(tagData[3]);
      tagStr = tagStr + String(tagData[4]);
      
      tagStr.toCharArray(str_msg.data,11);
      //Serial.println(tagWord);
     
     // str_msg.data = tagWord;
      pub_tag.publish(&str_msg);
      nodeHandler.spinOnce(); 
  }

 }// end loop()
 
 
  
  

