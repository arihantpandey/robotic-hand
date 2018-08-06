#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo0;
int pos1, pos2, pos3, pos4, po5 = 0;
int analogPin0 = A0;
int analogPin1 = A1;
int analogPin2 = A2;
int analogPin3 = A3;
int analogPin4 = A4;
int analogValue0, analogValue1, analogValue2, analogValue3, analogValue4, analogValue5 = 0;
int inputV = 5;
float outputV0, outputV1, outputV2, outputV3, outputV4 = 0;
float R = 22000;
float resistance0, resistance1, resistance2, resistance3, resistance4 = 0;
float ratio = 0;
int servopin0 = 13;
int servopin1 = 12;
int servopin2 = 8;
int servopin3 = 7;
int servopin4 = 4;

void setup() {
  Serial.begin(2400);

  pinMode(servopin0, OUTPUT);
  pinMode(servopin1, OUTPUT);
  pinMode(servopin2, OUTPUT);
  pinMode(servopin3, OUTPUT);
  pinMode(servopin4, OUTPUT);

  servo0.attach(servopin0);
  servo1.attach(servopin1);
  servo2.attach(servopin2);
  servo3.attach(servopin3);
  servo4.attach(servopin4);

}
int findResistance(int analogValue, int outputV);

void loop() {
  analogValue0 = analogRead(analogPin0);
    resistance0 = findResistance(analogValue0, outputV0);
    Serial.print("Resistance0: ");
    Serial.println(resistance0);

  analogValue1 = analogRead(analogPin2);
  resistance1 = findResistance(analogValue1, outputV1);
  Serial.print("Resistance1: ");
  Serial.println(resistance1);
  Serial.println(analogValue0);

  analogValue2 = analogRead(analogPin2);
  resistance2 = findResistance(analogValue2, outputV2);
  Serial.print("Resistance2: ");
  Serial.println(analogValue1);

  analogValue3 = analogRead(analogPin3);
    resistance3 = findResistance(analogValue3, outputV3);
    Serial.print("Resistance3: ");
    Serial.println(resistance3);
  
  analogValue4 = analogRead(analogPin4);
    resistance4 = findResistance(analogValue4, outputV4);
    Serial.print("Resistance4: ");
    Serial.println(resistance4);

  //  while (resistance > 100000) {
  //  for (pos = servo.read(); pos <= 180; pos += 1) {
  //    servo.write(pos);
  //    delay(15);
  //    resistance = findResistance();
  //  }
  servo0.write((analogValue0 - 150) / 2);
  servo1.write((analogValue1 - 150) / 2);
  servo2.write((analogValue2 - 150) / 2);
  servo3.write((analogValue3 - 150) / 2);
  servo4.write((analogValue4 - 150) / 2);
  delay(15);
  //  }

}

int findResistance(int analogValue, int outputV) {
  if (analogValue) {
    outputV = analogValue * inputV / 1024.0;
    ratio = (inputV / outputV) - 1;
    return R * ratio;
  }
}

