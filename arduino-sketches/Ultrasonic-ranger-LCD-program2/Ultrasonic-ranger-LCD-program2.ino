#include "TM1637.h" 
#include "Ultrasonic.h"
/* Macro Define */
#define CLK               40                  /* 4-digital display clock pin */
#define DIO               39                 /* 4-digital display data pin */
#define BLINK_LED         RED_LED            /* blink led */
#define ULTRASONIC_PIN    38                  /* pin of the Ultrasonic Ranger */

/* Global Variables */
TM1637 tm1637(CLK, DIO);                  /* 4-digital display object */
Ultrasonic ultrasonic(ULTRASONIC_PIN);    /* Ultrasonic Ranger object */
int distance = 0;                         /* variable to store the distance to obstacles in front */
int blink_interval = 0;                   /* led delay time */
int8_t bits[4] = {0};                     /* array to store the single bits of the value */

/* the setup() method runs once, when the sketch starts */
void setup() {
    
    /* Initialize 4-digital display */
    tm1637.init();
    tm1637.set(BRIGHT_TYPICAL);
  
    /* declare the red_led pin as an OUTPUT */
    pinMode(RED_LED, OUTPUT);
  
}

/* the loop() method runs over and over again */
void loop() {   
  
    distance = ultrasonic.MeasureInCentimeters();   /* read the value from the sensor */   
    
    memset(bits, 0, 4);                             /* reset array when we use it */
    for(int i = 3; i >= 0; i--) {
        /* get single bits of the analog value */
        bits[i] = distance % 10;
        distance = distance / 10;  
        tm1637.display(i, bits[i]);                 /* display by 4-digital display */
    }
    delay(100);
}
