/*
 Adapted from Knob by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
 by Jody Culkin and Eric Hagan
*/
//modified July 25, 2017

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2; //add another servo object for 2nd motor

int potpin = 0;  // analog pin used to connect the potentiometer
int val = 0;    // variable to read the value from the analog pin
int pval = 0; //keeping track of the previous value

int servopin1 = 9;
int servopin2 = 10;

void setup(){
  myservo1.attach(servopin1);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(servopin2); //attach 2nd servo
  myservo1.write(90); //move 1st servo to midpoint
  myservo2.write(90); //move 2nd servo to midpoint
}

void loop(){
  pval = val; //set previous value from potentiometer reading to current readiing
  val = analogRead(potpin); //check value from potentiometer on pin A0
  val = map(val, 0, 1023, 0, 180);  //map value to range used by servo
  if (val!= pval){ // if there has been a change, call turnServos function
    turnServos();
  }
}
//turnServos is a custom function that gets called by loop
void turnServos() {
  if (val > 0 && val <= 45) { //if val is between0 and 45 
    myservo1.write(45); //set position of first servo
    myservo2.write(135); //set position of second servo
  }
  if (val > 45 && val <= 90) { //if val is between 45 and 90
    myservo1.write(0); //set position of servos
    myservo2.write(180);
  }
  if (val > 90 && val <= 135) { //if val is between 90 and 135
    myservo1.write(180); //set position of servos
    myservo2.write(0);
  }

  if (val > 135 && val <= 180) { //if val is between 135 and 180
    myservo1.write(45); //set position of servos
    myservo2.write(45);  
  }
  delay(15); //short pause for servo to move
}

