#include<Servo.h>

Servo myServo;

void setup() {

  myServo.attach(9);

}

void loop() {

  //move servo to specific angles
  myServo.write(179);
  delay(1000);
  myServo.write(1);
  delay(1000);

  //move servo slowly
  for(int i=0; i<180; ++i) {
    myServo.write(i);
    delay(50);
  }

}
