/* This program will allow you to control the servo motor
 * using the potentiometer
 */
#include <Servo.h>

Servo myservo;    // create servo object to control a servo
int potpin = 0;   // analog pin used to connect the potentiometer
int val;          // variable to read the value from the analog pin

void setup() 
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180 as Servo can rotate up to 180 degrees)
  // Parameters of map
  // value: the number to map
  // fromLow: the lower bound of the value’s current range
  // fromHigh: the upper bound of the value’s current range
  // toLow: the lower bound of the value’s target range
  // toHigh: the upper bound of the value’s target range  
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
