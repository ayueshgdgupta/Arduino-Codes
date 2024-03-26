/* 
PyroSensor

Detect Motion using PIR Sensor and Arduino Uno
Upon detection of motion, "Object detected" is printed on serial monitor of Arduino. When there is no motion, "No object in sight" is printed on serial monitor of Arduino. 

*/

const int PIR_SENSOR_OUTPUT_PIN = 4;
int warm_up;

void setup() {
 pinMode(PIR_SENSOR_OUTPUT_PIN, INPUT);
 Serial.begin(9600); 
 delay(20000);
} 

void loop() {
 int sensor_output;
 sensor_output = digitalRead(PIR_SENSOR_OUTPUT_PIN);
 if( sensor_output == LOW )
 {
 if( warm_up == 1 )
 {
 Serial.print("Warming Up\n\n");
 warm_up = 0;
 delay(2000);
 }
 Serial.print("No object in sight\n\n");
 delay(1000);
 }
 else
 {
 Serial.print("Object detected\n\n");
 warm_up = 1;
 delay(1000);
 }
} 






//Interfacing with Smoke Sensor 

int sensorValue;
int digitalValue;

void setup()
{
 Serial.begin(9600); 
 pinMode(13, OUTPUT);
 pinMode(2, INPUT);
} 

void loop()
{
 sensorValue = analogRead(0); 
 digitalValue = digitalRead(2);
 if (sensorValue > 400)
 {
 digitalWrite(13, HIGH);
 }
 else
 digitalWrite(13, LOW);
 Serial.println(sensorValue, DEC); 
 Serial.println(digitalValue, DEC);
 delay(1000);
}







// Program for Temperature and Humidity Measurement using DHT11

#include"DHT.h"
DHT dht;

void setup()
{
 Serial.begin(9600);
 Serial.println();
 Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
 dht.setup(2); 
}


void loop()
{
 delay(dht.getMinimumSamplingPeriod()); 
 float humidity = dht.getHumidity(); 
 float temperature = dht.getTemperature();

 Serial.print(dht.getStatusString()); 
 Serial.print("\t");
 Serial.print(humidity, 1);
 Serial.print("\t\t");
 Serial.print(temperature, 1);
 Serial.print("\t\t");
 Serial.println(dht.toFahrenheit(temperature), 1); 
} 




























//Pressure Sensor

* This is a library for the BMP280 humidity, temperature & pressure sensor and
 These sensors use I2C or SPI to communicate, 2 or 4 pins are required
 to interface. */
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#define BMP_SCK (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS (10)
Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);
void setup() {
 Serial.begin(9600);
 while ( !Serial ) delay(100); // wait for native usb
 Serial.println(F("BMP280 test"));
 unsigned status;
 // status = bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID);
 status = bmp.begin(0x76);

if (!status) {
 Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
 "try a different address!"));
 Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(),16);
 Serial.print(" ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
 Serial.print(" ID of 0x56-0x58 represents a BMP 280,\n");
 Serial.print(" ID of 0x60 represents a BME 280.\n");
 Serial.print(" ID of 0x61 represents a BME 680.\n");
 while (1) delay(10);
 }
 /* Default settings from datasheet. */
 bmp.setSampling(Adafruit_BMP280::MODE_NORMAL, /* Operating Mode. */
 Adafruit_BMP280::SAMPLING_X2, /* Temp. oversampling */
 Adafruit_BMP280::SAMPLING_X16, /* Pressure oversampling */
 Adafruit_BMP280::FILTER_X16, /* Filtering. */
 Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
} 
void loop() {
 Serial.print(F("Temperature = "));
 Serial.print(bmp.readTemperature());
 Serial.println(" *C");
 Serial.print(F("Pressure = "));
 Serial.print(bmp.readPressure()/100.0F);
 Serial.println(" Pa");
 Serial.print(F("Approx altitude = "));
 Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
 Serial.println(" m");
 Serial.println();
 delay(2000);
} 