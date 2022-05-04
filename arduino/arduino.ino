#include "BluetoothSerial.h"
    
BluetoothSerial SerialBT;

     
void setup()
{
  Serial.begin(9600);
  delay(500);
  Serial.print("sus");
  pinMode(5,OUTPUT); //SET THIS TO ANALOG SOON! aloso might need to switch digitialWrite to analogWrite
  SerialBT.begin("ESP32");
  delay(1000);
}
     
void loop()
{
  String inputFromOtherSide;
  if (SerialBT.available()) {
    inputFromOtherSide = SerialBT.readString(); //read data being sent to us and save it to variable
    if (inputFromOtherSide = "lshort"){
    SerialBT.println("1");
    digitalWrite(5,70);
    delay(1500);
    digitalWrite(5,0);
    SerialBT.println("2");
    inputFromOtherSide = 0;
    }
    if (SerialBT.available()) {
    inputFromOtherSide = SerialBT.readString(); //read data being sent to us and save it to variable
    if (inputFromOtherSide = "mshort"){
    SerialBT.println("1");
    digitalWrite(5,160);
    delay(1500);
    digitalWrite(5,0);
    SerialBT.println("2");
    inputFromOtherSide = 0;
    }
    if (SerialBT.available()) {
    inputFromOtherSide = SerialBT.readString(); //read data being sent to us and save it to variable
    if (inputFromOtherSide = "hshort"){
    SerialBT.println("1");
    digitalWrite(5,230);
    delay(1500);
    digitalWrite(5,0);
    SerialBT.println("2");
    inputFromOtherSide = 0;
    }
    inputFromOtherSide = SerialBT.readString();
    if (inputFromOtherSide = "llong"){
    SerialBT.println("1");
    digitalWrite(5,70);
    delay(2500);
    digitalWrite(5,0);
    SerialBT.println("2");
    inputFromOtherSide = 0;
    }
    inputFromOtherSide = SerialBT.readString();
    if (inputFromOtherSide = "mlong"){
    SerialBT.println("1");
    digitalWrite(5,160);
    delay(2500);
    digitalWrite(5,0);
    SerialBT.println("2");
    inputFromOtherSide = 0;
    }
    inputFromOtherSide = SerialBT.readString();
    if (inputFromOtherSide = "hlong"){
    SerialBT.println("1");
    digitalWrite(5,230);
    delay(2500);
    digitalWrite(5,0);
    SerialBT.println("2");
    inputFromOtherSide = 0;
    }
    inputFromOtherSide = SerialBT.readString();
    if (inputFromOtherSide = "lmed"){
    SerialBT.println("1");
    digitalWrite(5,70);
    delay(2500);
    digitalWrite(5,0);
    SerialBT.println("2");
    inputFromOtherSide = 0;
    }
    inputFromOtherSide = SerialBT.readString();
    if (inputFromOtherSide = "mmed"){
    SerialBT.println("1");
    digitalWrite(5,160);
    delay(2500);
    digitalWrite(5,0);
    SerialBT.println("2");
    inputFromOtherSide = 0;
    }
    inputFromOtherSide = SerialBT.readString();
    if (inputFromOtherSide = "hmed"){
    SerialBT.println("1");
    digitalWrite(5,230);
    delay(2500);
    digitalWrite(5,0);
    SerialBT.println("2");
    inputFromOtherSide = 0;
    }
  }
}
