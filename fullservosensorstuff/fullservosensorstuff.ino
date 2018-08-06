#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo0;
int pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0, po5 = 0;
int analogPin0 = A0;
int analogPin1 = A1;
int analogPin2 = A2;
int analogPin3 = A3;
int analogPin4 = A4;
int analogValue0 = 0, analogValue1 = 0, analogValue2 = 0, analogValue3 = 0, analogValue4 = 0, analogValue5 = 0;
int inputV = 5;
float outputV = 0;
float R = 12000;
long resistance0, resistance1, resistance2, resistance3, resistance4 = 0;
float ratio = 0;
int servopin0 = 13;
int servopin1 = 11;
int servopin2 = 8;
int servopin3 = 7;
int servopin4 = 4;
int value0, value1, value2, value3, value4;


void setup() {
  pinMode(servopin0, OUTPUT);
  pinMode(servopin1, OUTPUT);
  pinMode(servopin2, OUTPUT);
  pinMode(servopin3, OUTPUT);
  pinMode(servopin4, OUTPUT);


  pinMode(analogPin0, INPUT);
  pinMode(analogPin1, INPUT);
  pinMode(analogPin2, INPUT);
  pinMode(analogPin3, INPUT);
  pinMode(analogPin4, INPUT);

  Serial.begin(2400);

  servo0.attach(servopin0);
  servo1.attach(servopin1);
  servo2.attach(servopin2);
  servo3.attach(servopin3);
  servo4.attach(servopin4);
  //  servo1.write(200);
  //  servo2.write(200);
  //  servo3.write(200);
  //  servo4.write(200);
  //  servo0.write(200);
}
int findResistance0(int analogValue);
int findResistance1(int analogValue);
int findResistance2(int analogValue);
int findResistance3(int analogValue);
int findResistance4(int analogValue);

void loop() {
  analogValue0 = analogRead(analogPin0);
  findResistance0(analogValue0);
  Serial.print("Resistance0: ");
  Serial.println(resistance0);

  analogValue1 = analogRead(analogPin1);
  findResistance1(analogValue1);
  //servo1.write(-200);
  Serial.print("Resistance1: ");
  Serial.println(resistance1);


  analogValue2 = analogRead(analogPin2);
  findResistance2(analogValue2);
  Serial.print("Resistance2: ");
  Serial.println(resistance2);
  Serial.println(analogValue2);

  analogValue3 = analogRead(analogPin3);
  findResistance3(analogValue3);
  Serial.print("Resistance3: ");
  Serial.println(resistance3);

  analogValue4 = analogRead(analogPin4);
  findResistance4(analogValue4);
  Serial.print("Resistance4: ");
  Serial.println(resistance4);

  //    while (resistance > 100000) {
  //    for (pos = servo.read(); pos <= 180; pos += 1) {
  //      servo.write(pos);
  //      delay(15);
  //      resistance = findResistance();
  //    }

  value0 = map(resistance0, 40000, 100000, 180, 0);
  value0 = constrain(value0, 0, 180);

  value1 = map(resistance1, 16000, 80000, 180, 0);
  value1 = constrain(value1, 0, 180);

  value2 = map(resistance2, 11000, 90000, 180, 0);
  value2 = constrain(value2, 0, 180);

  value3 = map(resistance3, 18000, 70000, 180, 0);
  value3 = constrain(value3, 0, 180);

  value4 = map(resistance4, 40000, 100000, 180, 0 );
  value4 = constrain(value4, 0, 180);
  //
  //  servo0.write(((analogValue0 - 150) / 2));
  //  servo1.write(((analogValue1 - 150) / 2));
  //  servo2.write(((analogValue2 - 150) / 2));
  //  servo3.write(((analogValue3 - 150) / 2));
  //  servo4.write(((analogValue4 - 150) / 2));

  servo0.write(value0);
  servo1.write(value1);
  servo2.write(value2);
  servo3.write(value3);
  servo4.write(value4);
  delay(15);
  //  }

}

int findResistance0(int analogValue) {
  if (analogValue) {
    outputV = analogValue * inputV / 1024.0;
    ratio = (inputV / outputV) - 1;
    resistance0 = (22000 * ratio);
    return 0;
  }
}
int findResistance1(int analogValue) {
  if (analogValue) {
    outputV = analogValue * inputV / 1024.0;
    ratio = (inputV / outputV) - 1;
    resistance1 = (R * ratio);
    return 0;
  }
}
int findResistance2(int analogValue) {
  if (analogValue) {
    outputV = analogValue * inputV / 1024.0;
    ratio = (inputV / outputV) - 1;
    resistance2 = (R * ratio);
    return 0;
  }
}
int findResistance3(int analogValue) {
  if (analogValue) {
    outputV = analogValue * inputV / 1024.0;
    ratio = (inputV / outputV) - 1;
    resistance3 = (R * ratio);
    return 0;
  }
}
int findResistance4(int analogValue) {
  if (analogValue) {
    outputV = analogValue * inputV / 1024.0;
    ratio = (inputV / outputV) - 1;
    resistance4 = (174 * ratio);
    return 0;
  }
}


