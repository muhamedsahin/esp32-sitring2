#include <SoftwareSerial.h>

SoftwareSerial commy(8,9);
SoftwareSerial esp(10, 11);

String delimiter = "/9j/";
String asd = "";

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  commy.begin(9600);
  esp.begin(9600);
}

void loop() {
  /*
  commy.listen();
  while (commy.available() > 0) {
    char inByte = commy.read();
    Serial.write(inByte);
  }
  // Serial.println();
  
  esp.listen();
  */

  if (asd.lastIndexOf(delimiter) > 1) {
    //Serial.println(asd.substring(asd.indexOf(delimiter), asd.lastIndexOf(delimiter)));
    asd = asd.substring(asd.lastIndexOf(delimiter), asd.length());
  }
  
  while (esp.available() > 0) {
    char inByte = esp.read();
    Serial.write(inByte);
    //commy.write(inByte);
    asd += inByte;
    
  }

  
  
 
  //Serial.println(asd);
  
  //Serial.println();
  /*
  while (commy.available() > 0) {
    char inByte = commy.read();
    Serial.write(inByte);
  }
  */
  
  // Serial.println();

  
}
