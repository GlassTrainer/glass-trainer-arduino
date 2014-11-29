// Another simple sketch to detect the Southern Hemisphere
// Assumes: LED on pin 13, GPS connected to pins 2/3
// (Optional) Serial debug console attached to hardware serial port 0/1

#include "TinyGPS.h"
#include "SoftwareSerial.h"
#include <Wire.h> 
#include <SFE_MMA8452Q.h>

#define HEMISPHERE_PIN 13
#define GPS_RX_PIN 0
#define GPS_TX_PIN 1

MMA8452Q accel;

TinyGPS gps; // create a TinyGPS object
SoftwareSerial ss(GPS_RX_PIN, GPS_TX_PIN); // create soft serial object

void setup()
{
  Serial.begin(57600); // for debugging
  ss.begin(57600); // Use Soft Serial object to talk to GPS
  pinMode(HEMISPHERE_PIN, OUTPUT);
  digitalWrite(HEMISPHERE_PIN, LOW); // turn off LED to start
  
  accel.init();
}
void loop()
{
  delay(2000);

  while (ss.available())
  {
    int c = ss.read();
    Serial.write(c); 
     //acceleration

  }
  
    Serial.print("\n");
    if (accel.available())
  {
    accel.read();
    printCalculatedAccels();
    //To separate one line
    Serial.print("\n");
    //delay(2000);
  }

}

    void printCalculatedAccels()
  { 
    Serial.print("cx:");
    Serial.print(accel.cx, 3);
    Serial.print(",");
    
    Serial.print("cy:");
    Serial.print(accel.cy, 3);
    Serial.print(",");
    
    Serial.print("cz:");
    Serial.print(accel.cz, 3);
  
  }    
