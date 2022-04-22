#include "BluetoothSerial.h"
    
BluetoothSerial SerialBT;

     
void setup()
{
  pinMode(5,OUTPUT);
  SerialBT.begin("ESP32");
  delay(1000);
}
     
void loop()
{
  String inputFromOtherSide;
  String inputFromOtherSide2;
  if (SerialBT.available()) {
    inputFromOtherSide = SerialBT.readString(); //read data being sent to us and save it to variable
    if (inputFromOtherSide = "short"){
    SerialBT.println("1");
    digitalWrite(5,HIGH);
    delay(1500);
    digitalWrite(5,LOW);
    SerialBT.println("2");
    }
    inputFromOtherSide2 = SerialBT.readString();
    if (inputFromOtherSide2 = "long"){
    SerialBT.println("3");
    digitalWrite(5,HIGH);
    delay(2500);
    digitalWrite(5,LOW);
    SerialBT.println("4");
    }
  }
}
