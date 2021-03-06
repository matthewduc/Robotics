#include <AFMotor.h>

AF_DCMotor Lmotor(1);
AF_DCMotor Rmotor(2);

void setup() {

  Serial.begin(9600);
  Lmotor.setSpeed(150);
  Rmotor.setSpeed(150);
  Lmotor.run(RELEASE);
  Rmotor.run(RELEASE);
 
}

void loop() {

  Lmotor.run(FORWARD);
  Rmotor.run(FORWARD);
  delay(1000);
  Lmotor.run(BACKWARD);
  Rmotor.run(BACKWARD);
  delay(1000);

}

// - - - FUNCTION - - -

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
