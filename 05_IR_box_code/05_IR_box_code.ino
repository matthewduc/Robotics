#include <AFMotor.h>

AF_DCMotor Lmotor(1);
AF_DCMotor Rmotor(2);

int value;
int analogPin = 1;

void setup() {

  Serial.begin(9600);
  Lmotor.setSpeed(150);
  Rmotor.setSpeed(150);
  Lmotor.run(RELEASE);
  Rmotor.run(RELEASE);
 
}

void loop() {

  //USING IF STATEMENT
  value = analogRead(analogPin);

  if(value > 800) {
    Serial.println("detecting IR: TRUE");
    moveRobot("forward");
  }
  else {
    Serial.println("detecting IR: FALSE");
    moveRobot("backward");
    delay(500);
    moveRobot("right");
    delay(500);
  }



  //WHILE LOOP
  /*
  
  while(value > 800) {
    Serial.println("detecting IR: TRUE");
    moveRobot("forward");
  }

  Serial.println("detecting IR: FALSE");
  moveRobot("backward");
  delay(500);
  moveRobot("right");
  delay(500);
   
  */

}

void moveRobot(String d) {

  if(d=="forward") {
    Lmotor.run(FORWARD);
    Rmotor.run(FORWARD);
  }
  else if(d=="backward") {
    Lmotor.run(BACKWARD);
    Rmotor.run(BACKWARD);
  }
  else if(d=="right") {
    Lmotor.run(FORWARD);
    Rmotor.run(BACKWARD);
  }
  else if(d=="left") {
    Lmotor.run(BACKWARD);
    Rmotor.run(FORWARD);
  }
  else if(d=="stop") {
    Lmotor.run(RELEASE);
    Rmotor.run(RELEASE);
  }
}
