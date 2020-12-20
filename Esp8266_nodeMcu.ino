#include <SoftwareSerial.h>
//#include <ESP8266WiFi.h>
//#include <PubSubClient.h>
//String kill="";
SoftwareSerial swSer(14, 12, false, 128); //Define hardware(ESP8266) connections

void setup() {
  Serial.begin(115200);   //Initialize hardware serial with baudrate of 115200
  swSer.begin(115200);    //Initialize software serial with baudrate of 115200

  Serial.println("\nSoftware serial test started");

//  for (char ch = ' '; ch <= 'z'; ch++) {  //send serially a to z on software serial
//    swSer.write(ch);
//  }
//  swSer.println("");

}
String yash;
void loop() {
if (swSer.available() > 0) {  //wait for data at software serial
//Serial.write(swSer.read());
yash=swSer.readString();
Serial.print(yash);

//


//   // yield();
 }
//String ="this,is,my,destiny";
//  while (Serial.available() > 0) { //wait for data at hardware serial
//    swSer.println(Serial.read());     //send data recived from hardware serial to software serial
//  }

}
