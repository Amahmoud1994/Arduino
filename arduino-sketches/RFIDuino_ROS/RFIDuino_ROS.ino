#include <ros.h>
#include <RFIDuino.h> //include the RFIDuino Library
#include <std_msgs/String.h>

RFIDuino myRFIDuino(1.1);     //initialize an RFIDuino object for hardware version 1.1

//initialize the Node handeler
ros::NodeHandle  nodeHandler;
std_msgs::String str_msg;

char tagWord[8];
String tagStr;
ros::Publisher pub_tag("/tagRead", &str_msg);


//enter your ID numbers below as a 'key' tag
byte keyTag[5] ={37,0,0,161,253};  //an array that will hold all of our 'key tags'. Key tags are treated differently from other tags read

byte tagData[5];                   //Holds the ID numbers from the tag
boolean verifyKey = false;         //true when a verified tag has been determined to match the key tag, false otherwise
  
void setup()
{
  //The RFIDUINO hardware pins and user outputs(Buzzer / LEDS) are all initialized via pinMode() in the library initialization, so you don not need to to that manually
  
  nodeHandler.initNode();
  nodeHandler.advertise(pub_tag);
  Serial.begin(9600);

}

void loop()
{    
   //scan for a tag - if a tag is sucesfully scanned, return a 'true' and proceed
  if(myRFIDuino.scanForTag(tagData) == true)
  {
    verifyKey = myRFIDuino.compareTagData(tagData, keyTag);//run the comparetagData to check the tag just read against the 'key' tag we defined.
    if(verifyKey == true)//if a 'true' is returned by comparetagData, the current read is a key tag
    {                       
      digitalWrite(myRFIDuino.led2,HIGH);         //turn green LED on
      myRFIDuino.successSound();                  //Play a 'success' sound from the buzzer, 3 notes acsending 
      delay(250);                                 //wait for a period before turning off the LED
      digitalWrite(myRFIDuino.led2,LOW);       //turn the green LED off
       
  }
  
    else//otherwise the tag is not a key tag
    {        
      digitalWrite(myRFIDuino.led1,HIGH);         //turn red LED on
      myRFIDuino.errorSound();                    //Play a 'error' sound from the buzzer, 3 notes acsending 
      delay(250);                                 //wait for a period before turning off the LED
      digitalWrite(myRFIDuino.led1,LOW);          //turn the red LED off        
    }
    
      tagStr = String(tagData[0]);
      tagStr = tagStr + String(tagData[1]);
      tagStr = tagStr + String(tagData[2]);
      tagStr = tagStr + String(tagData[3]);
      tagStr = tagStr + String(tagData[4]);
      
      tagStr.toCharArray(tagWord,11);
      Serial.println(tagWord);
     
      str_msg.data = tagWord;
      pub_tag.publish(&str_msg);
      nodeHandler.spinOnce(); 

  }    
}//end loop()
          
