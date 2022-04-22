#include "BluetoothSerial.h"
    
BluetoothSerial SerialBT;
     
void setup()
{
  SerialBT.begin("ESP32test");
  delay(1000);
}
     
void loop()
{
  String inputFromOtherSide;
  if (SerialBT.available()) {
    inputFromOtherSide = SerialBT.readString(); //read data being sent to us and save it to variable
    if inputFromOtherSide = "short"
    //write arduino digital pin high, then wait, then digital pin low code.
    SerialBT.println("1");
    if inputFromOtherside = "long"
    //you get the gist.
  }
}