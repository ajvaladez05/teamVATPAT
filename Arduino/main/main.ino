#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include "utility/Adafruit_PWMServoDriver.h"
// Program definitions to save on memory
#define RPM 25 // Default rpm for each motor
#define _MOTOR_ONE_LOC 1 // Setting the location of motor one
#define _MOTOR_TWO_LOC 2 // Setting the location of motor two
#define _INV_SWITCH_ONE 51 // Setting the digital input of inventory switch one
#define _INV_SWITCH_TWO 53 // Setting the digital input of inventory switch two
#define _INV_LED_ONE 31 // Setting the digital output of the inventory LED one
#define _INV_LED_TWO 33 // Setting the digital output of the inventory LED two


void setup() {
  // put your setup code here, to run once:
  
   /***************************************************************************************
  * 
  * Setting up the PINS
  *
  ***************************************************************************************/
  pinMode(_INV_SWITCH_ONE, INPUT); // Setting the pins for inventory switches to input
  pinMode(_INV_SWITCH_TWO, INPUT);
  pinMode(_INV_LED_ONE, OUTPUT); // Setting the pins for inventory LEDs. 
  pinMode(_INV_LED_TWO, OUTPUT);
  
  int invSwitchOne = 0; // Variable for inventory switch states
  int invSwitchTwo = 0;
  
  
  
  
  /***************************************************************************************
  * 
  * Setting up the serial connection
  *
  ***************************************************************************************/
  
  Serial.begin(9600);
  
  Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // Motor Shield object. I would assume it instantiates the shield. Need to do once


  /***************************************************************************************
  *
  * getStepper(steps,stepper#) steps indicates how many steps per revolution the motor has.
  * Stepper# is which port the stepper is connected to. If using M1 and M2, use port 1. If 
  * using M3 and M4, use port 2. 
  *
  ****************************************************************************************/

  Adafruit_StepperMotor *myMotor_one = AFMS.getStepper(200,_MOTOR_ONE_LOC); // This definitely needs a change
  setSpeed(RPM);

}

void loop() {
  // put your main code here, to run repeatedly:
  /***************************************************************************************
  *
  * Check the inventory switches. 
  *
  ****************************************************************************************/
  
  
  
  
}
