//To interface with 4 by 1 Keypad

const int buttonPin[] = {7,6,5,4}; 
const int ledPin = 13; 

int buttonState = 1; 
void setup() {

 pinMode(ledPin, OUTPUT); 
 Serial.begin(9600); 
 for(int x=0; x<4; x++) 
 pinMode(buttonPin[x], INPUT_PULLUP);

}
void loop(){

 for(int x=0; x<4; x++) 
 {
 buttonState = digitalRead(buttonPin[x]);
 if(buttonState==LOW)
 {
 switch(x)
 {
 case 0: Serial.print(2); Serial.println(" is Pressed"); break;
 case 1: Serial.print(1); Serial.println(" is Pressed"); break;
 case 2: Serial.print(4); Serial.println(" is Pressed"); break;
 case 3: Serial.print(3); Serial.println(" is Pressed"); break;
 }
 delay(100);
 }
 }

}




//To interface with 4 by 4 Keypad 

#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 3;
char keys[ROWS][COLS] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'}, {'*','0','#'} };
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
 Serial.begin(9600);
}

void loop(){
 char key = keypad.getKey();

 if (key){
 Serial.print("Key Pressed : ");
 Serial.println(key);
 }
} 
