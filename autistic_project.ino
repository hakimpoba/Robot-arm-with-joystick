#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver myServo = Adafruit_PWMServoDriver();
//the values of SERVOMIN and SERVOMAX is the speed of clockwise and anti-clockwise
#define SERVOMIN 150
#define SERVOMAX 600
#define PIN_ANALOG_X 0
#define PIN_ANALOG_Y 1
uint8_t servonum = 1;
uint8_t numberOfServos = 6;

void setup() {
  Serial.begin(9600);
  myServo.begin();
  myServo.setPWMFreq(60);
  delay(10);
}

void loop() {
//  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++){
//    myServo.setPWM(servonum, 0, pulselen);
//  }
//  delay(500);
//  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--){
//    myServo.setPWM(servonum, 0, pulselen);
//  }
//  delay(500);
 // Print x axis values

 Serial.print("x: ");

 Serial.println(analogRead(PIN_ANALOG_X));

 // Print y axis values
int halal_dude =analogRead(PIN_ANALOG_X);
 Serial.print("y: ");

 Serial.println(analogRead(PIN_ANALOG_Y));


//if analog stick in the middle it will stop x axis only for now
 if (halal_dude == 491){
  stop();
 }
 //if to the right clockwise
 else if(halal_dude > 491){
    rotateTo(SERVOMIN);
 }
 // else anti clockwise
else{
  rotateTo(SERVOMAX);  
}

  delay(500);
  

}
void rotateTo(int position){
  position = constrain(position, SERVOMIN,SERVOMAX);
  myServo.setPWM(0,0,position);
}
void stop(){
  myServo.setPWM(0,0,0);
}
