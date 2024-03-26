LED ON & OFF

//To turn ON & OFF LED

#define LED_PIN 13 
void setup() {
 pinMode(LED_PIN, OUTPUT);
}

void loop() {
 digitalWrite(LED_PIN, HIGH); 
 delay(1000); 
 digitalWrite(LED_PIN, LOW); 
 delay(1000); 
}


//. To fade an LED repeatedly. 

int led = 9; 
int brightness = 0;
int fadeAmount = 5; 

void setup() {
 pinMode(led, OUTPUT); }

void loop() {
 analogWrite(led, brightness); 
 brightness = brightness + fadeAmount; 
 if (brightness <= 0 || brightness >= 255) { 
 fadeAmount = -fadeAmount;
 }

 delay(50);
}



//To interface with pushbutton switch

const int buttonPin = 2; 
const int ledPin = 8;

int bPresentState = 1;
int bPreviousState = 1;

void setup() {

 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin,INPUT); 
 Serial.begin(9600); 
}

void loop(){

 bPresentState = digitalRead(buttonPin);
 if(bPresentState!=bPreviousState)
 {
 if(bPresentState==LOW)
 Serial.println("Button State is LOW");

 if(bPresentState==HIGH)
 Serial.println("Button State is HIGH");
 bPreviousState=bPresentState;
 }

 // delay(500);

} 