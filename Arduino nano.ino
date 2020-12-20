/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo and Micro support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

SoftwareSerial mySerial(10, 11); // Define RX, TX

long duration; // variable for the duration of sound wave travel
int di; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO Neno");
  // Open serial communications and wait for port to open:
  Serial.begin(9600);//arduino communicate with com.
  Serial.println("reset");
  mySerial.begin(115200);//arduino commu. with ESp8266
 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    Serial.println("\n\nString Constructors:");
  Serial.println();
  }


  Serial.println("Goodnight moon!"); 

  // set the data rate for the SoftwareSerial port
  
}
String stringOne;
void loop() { // run over and over
  //**************************for sensor data****************************************
  // //////////////////////////////////Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  di= duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
//mySerial.print("D:");
//mySerial.print(distance);
 
  String(" cm");
//  mySerial.print(" cm");
//**************************for sensor data****************************************
// read the input on analog pin 0:
  int sv = analogRead(A0);
  // print out the value you read:
//mySerial.print("__G: ");
//mySerial.print(sensorValue  );
//mySerial.print("\t");
String mainst;
/////IN formate of "D<dis>_<val>"
String a ="D";
a+="(";
a+=String(int(di));
a +="_";
a +=String (int(sv));
a +=")";
a +="$";
mainst = "";
mainst += a;
//Serial.print(mainst);



Serial.flush();
 
  if (mySerial.available()>0) {
//    Serial.write(mySerial.read()); 
  mySerial.print(mainst);
//  }
//  if (Serial.available()>0) {
//    Serial.flush();


//************************ For Word to String
// String stringTwo =  String("This");
  //Serial.println(stringTwo);      // prints "This is a string"
  //String stringOne;
  // concatenating two strings:
//  stringOne =  String(stringTwo + " is");
  // prints "This is a string with more":
  //Serial.println(stringOne);

  // concatenating two strings:
//  stringOne =  String(stringOne + " me");
  // prints "This is a string with more":
  //Serial.println(stringOne);
//  stringOne =  String(stringOne + " or you Say Yash");
  // prints "This is a string with more":
//  mySerial.println(stringOne);

//  For integer Value
//int i = 19398;
//stringOne=String(i);
//mySerial.println(stringOne);//communicate with ESP8266
//mySerial.println("basturd");
   delay(1000);
  }
//String subs="";
//stringOne="This is me or you say Yash";
//mySerial.println(stringOne);//"This is me or you say Yash"
//if (stringOne.substring(23) == "Yash") {
//    mySerial.println("It's match file");
//  delay(5000);

}
