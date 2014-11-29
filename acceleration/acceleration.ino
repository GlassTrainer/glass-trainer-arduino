
#include <Wire.h> 
#include <SFE_MMA8452Q.h>

MMA8452Q accel;

void setup()
{
  Serial.begin(9600);
  //Serial.println("Initilizating;");
  accel.init();
}


void loop()
{

  if (accel.available())
  {
    accel.read();
    printCalculatedAccels();
    //To separate one line
    Serial.print("\n");
    delay(2000);
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

/*
void printOrientation()
{
  byte pl = accel.readPL();
  switch (pl)
  {
  case PORTRAIT_U:
    Serial.print("Portrait Up");
    break;
  case PORTRAIT_D:
    Serial.print("Portrait Down");
    break;
  case LANDSCAPE_R:
    Serial.print("Landscape Right");
    break;
  case LANDSCAPE_L:
    Serial.print("Landscape Left");
    break;
  case LOCKOUT:
    Serial.print("Flat");
    break;
  }
}
*/
