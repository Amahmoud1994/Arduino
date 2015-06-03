/*
Buzzer Program
*/

const int tiltPin = 3;     // the number of the tilt pin
const int buzzerPin =  8;      // the number of the buzzer pin

// variables will change:
int tiltState = 0;         // variable for reading the tilt status

void setup() {
  // initialize the buzzer pin as an output:
  pinMode(buzzerPin, OUTPUT);      
  // initialize the tilt pin as an input:
  pinMode(tiltPin, INPUT);     
}

void loop(){
  // read the state of the tilt value:
  tiltState = digitalRead(tiltPin);

  // check if the tilt is close.
  // if it is, the tiltState is HIGH:
  if (tiltState == HIGH) {     
    // turn buzzer on:    
    digitalWrite(buzzerPin, HIGH);  
  } 
  else {
    // turn buzzer off:
    digitalWrite(buzzerPin, LOW); 
  }
}
