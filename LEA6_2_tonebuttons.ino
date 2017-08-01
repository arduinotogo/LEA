/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

modified 1 Aug 2017
by Jody Culkin and Eric Hagan
*/

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int buttonPin2 = 3;     // the number of the pushbutton pin

const int speakerPin = 11;    //the number of the speaker pin

const int ledPin = 13;       //the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the pushbutton pins as inputa:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);

  // initialize the LED pin and the Speaker pin as an output:
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the state of the pushbuttons value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  
  // check if the pushbutton is pressed.  
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    tone (speakerPin, 330);
  }

  else if (buttonState2 == HIGH) {
    digitalWrite(ledPin, HIGH);  
    tone (speakerPin, 294);
  }
  
  else {
    // turn LED off:
    noTone(11);
    digitalWrite(ledPin, LOW);
  }
}
