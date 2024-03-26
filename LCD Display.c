//Interface with Potentiometer and display reading in Arduino Serial Monitor. 

#include <LiquidCrystal.h>

void setup() {
 Serial.begin(9600); 
}
void loop() {

 int sensorValue = analogRead(A0); 

 Serial.println(sensorValue);
 delay(100);
}



/*
 The LiquidCrystal library works with all LCD displays that are compatible with the Hitachi HD44780 driver.
This sketch displays text sent over the serial port (e.g. from the Serial Monitor) on an attached 16x2 LCD
display.
 The circuit:
 * LCD RS pin to digital pin 12 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground * 10K resistor:
 * ends to +5V and ground * wiper to LCD VO pin (pin 3)
*/ 


#include <LiquidCrystal.h> 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
 lcd.begin(16, 2); 
 Serial.begin(9600); 
}

void loop() {
 if (Serial.available()) {
 delay(100);  
 lcd.clear();

 while (Serial.available() > 0) {

 lcd.write(Serial.read());
 }
 }
} 






//Display the reading received from potentiometer connected to Arduino Board on LCD Display. 


#include <LiquidCrystal.h> 

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {

 lcd.begin(16, 2); 
 Serial.begin(9600); 
}

void loop() {

int sensorValue = analogRead(A0); 
lcd.clear(); 
 lcd.write( sensorValue );
 delay(100);
} 