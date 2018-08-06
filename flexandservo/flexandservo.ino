#include <Servo.h>
Servo myservo;
int pos = 0;
int analogPin = A2;
int analogValue = 0;
int inputV = 3.3;
float outputV = 0;
float R1 = 10000;
float resistance = 0;
float ratio = 0;
int servopin = 12;
int val = 0;

void setup() {
  pinMode(servopin, OUTPUT);
  Serial.begin(2400);
  myservo.attach(servopin);
}

int findResistance(int analogValue) {
  //  analogValue = analogRead(analogPin);
  if (analogValue) {
    outputV = analogValue * inputV / 1024.0;
    resistance =  R1 * ratio;
  }
}

void loop() {
  analogValue = analogRead(analogPin);
  if (analogValue) {
    outputV = analogValue * inputV / 1024.0;
    ratio = (inputV / outputV) - 1;
    resistance =  R1 * ratio;
    findResistance(analogValue);
    Serial.print("Resistance: ");
    Serial.println(resistance);
    //  val = map(val, 400, 200, -255, 255);
    //  myservo.write(val);
    myservo.write((analogValue - 150) / 2);
  }
}


