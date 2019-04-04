#include <Arduino.h>
#include <Wire.h>

int joyX = 0;
int joyY = 1;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() {
  // put your main code here, to run repeatedly:
  servoVal = analogRead(joyX);
  servoVal = map(servoVal, 0, 1023, 0, 180);
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write('X'); // send one bytes
  Wire.write(joyX); // send one bytes
  Wire.endTransmission();    // stop transmitting

  servoVal = analogRead(joyY);
  servoVal = map(servoVal, 0, 1023, 70, 180);
  Wire.write('Y'); // send one bytes
  Wire.write(joyX); // send one bytes
  Wire.endTransmission();    // stop transmitting
}
