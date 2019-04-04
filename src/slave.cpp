#include <Arduino.h>
#include <Servo.h>
Servo servo1;
Servo servo2;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  servo1.attach(3);
  servo2.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}


void receiveEvent(int howMany) {
  char axis = Wire.read() // receive axis X or Y as char
  int  value = Wire.read();
  if( axis == 'X'){
    servo1.write(servoVal);
  } else if( axis == 'Y') {
    servo2.write(servoVal);
  }
  Serial.println(x);         // print the integer
}

/*
 // --> for the stream of char:
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}
*/
