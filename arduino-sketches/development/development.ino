#include <ros.h>
#include <sensor_msgs/Range.h>
#include <std_msgs/Bool.h>
#include "Ultrasonic.h"

ros::NodeHandle  nodeHandler;
//ros::NodeHandle  buttonNode;
sensor_msgs::Range range_msg;
ros::Publisher pub_range( "/ultrasound", &range_msg);
char frameid[] = "/ultrasound";
std_msgs::Bool pushed_msg;
ros::Publisher pub_button("/buttonPushed", &pushed_msg);

Ultrasonic ultrasonic(4);
const int button_pin = 7;

void setup() {
  nodeHandler.initNode();
  nodeHandler.advertise(pub_range);
 // buttonNode.initNode();
  nodeHandler.advertise(pub_button);
  range_msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
  range_msg.header.frame_id =  frameid;
  range_msg.field_of_view = 0.1;  // fake
  range_msg.min_range = 0.0;
  range_msg.max_range = 3.5;
  //Initialize an input pin for our push button
  pinMode(button_pin, INPUT);
  digitalWrite(button_pin, HIGH);
}

void loop()
{
  long RangeInCentimeters;
  RangeInCentimeters = ultrasonic.MeasureInCentimeters();
  range_msg.range = RangeInCentimeters;
  range_msg.header.stamp = nodeHandler.now();
  pub_range.publish(&range_msg);

  pushed_msg.data = digitalRead (button_pin);
  pub_button.publish(&pushed_msg);
 // buttonNode.spinOnce();
  nodeHandler.spinOnce();
}
