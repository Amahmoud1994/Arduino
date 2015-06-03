/*
 The circuit:
* LED attached from pin 3 to ground
* Button attached to pin 2 from +5V
* 10K resistor attached to pin 2 from ground 
* Button Control An LED 
*/

int button = 2; //the Grove port No. you attached a button to
int LED = 3; //the Grove port No. you attached an LED to
void setup(){
pinMode(button, INPUT); //set button as an INPUT device
pinMode(LED, OUTPUT); //set LED as an OUTPUT device
}
void loop(){
int buttonState = digitalRead(button); //read the status of the button
if(buttonState == 1) //get pressed on
digitalWrite(LED,1); //turn on the LED
else
digitalWrite(LED,0); //or not
}
