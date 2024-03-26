// Program for Stepper Motor

#include <Stepper.h>
const int stepsPerRevolution = 200; 
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int stepCount = 0; 

void setup() { 
}

void loop() {

 int sensorReading = analogRead(A0); 
 int motorSpeed = map(sensorReading, 0, 1023, 0, 100); 

 if (motorSpeed > 0) {
 myStepper.setSpeed(motorSpeed);
 myStepper.step(stepsPerRevolution / 100); 
 }
} 




//Servo Motor

/* (1) Program for Controlling a servo position using a potentiometer (variable resistor) */


#include <Servo.h>
Servo myservo; 
int potpin = 0;
int val; 

void setup() {
 myservo.attach(9); 
}

void loop() {
 val = analogRead(potpin); 
 val = map(val, 0, 1023, 0, 180); 
 myservo.write(val); 
 delay(15); 
} 






/* (2) Program to sweep the shaft of a RC servo motor back and forth across 180 degrees */


#include <Servo.h>
Servo myservo; 
int pos = 0; 


void setup() {
 myservo.attach(9); 
}


void loop() {
 for (pos = 0; pos <= 180; pos += 1) { 
 myservo.write(pos); 
 delay(15); 
 }
 for (pos = 180; pos >= 0; pos -= 1) { 
 myservo.write(pos); 
 delay(15); 
 }
}
