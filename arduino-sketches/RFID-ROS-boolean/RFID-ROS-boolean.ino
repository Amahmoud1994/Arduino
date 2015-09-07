#include <ros.h>
#include <RFIDuino.h> //include the RFIDuino Library
//#include <std_msgs/String.h>
#include <std_msgs/Bool.h>


//initialize the Node handeler
ros::NodeHandle  nodeHandler;
//std_msgs::String str_msg;
std_msgs::Bool tag_msg;

char tagWord[8];
String tagStr;
boolean tagBool;
ros::Publisher pub_tag("/tagRead", &tag_msg);

  
void setup()
{
  //The RFIDUINO hardware pins and user outputs(Buzzer / LEDS) are all initialized via pinMode() in the library initialization, so you don not need to to that manually
  
  nodeHandler.initNode();
  nodeHandler.advertise(pub_tag);
}

void loop()
{    
   
}//end loop()
          
