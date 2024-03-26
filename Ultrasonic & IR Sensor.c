

//Ultrasonic Sensor

const int trigPin = 3;
const int echoPin = 5;
float duration, distance;
void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 Serial.begin(9600);
}
void loop() {
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration* 0.0343)/2;
 Serial.print("Distance: ");
 Serial.println(distance);
 delay(100);
 } 



//IR Sensor

int IRSensor = 9; 
int LED = 13; 

void setup(){
 Serial.begin(115200); 
 Serial.println("Serial Working"); 
 pinMode(IRSensor, INPUT); 
 pinMode(LED, OUTPUT); 
}

void loop(){
 int sensorStatus = digitalRead(IRSensor); 
 if (sensorStatus == 1) 
 {
 digitalWrite(LED, LOW); // LED LOW
 Serial.println("Obstacle Detected!"); 
 }
 else {
 
 digitalWrite(LED, HIGH); 
 Serial.println("Obstacle Not Present!");
 }
} 
