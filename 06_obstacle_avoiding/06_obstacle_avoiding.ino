#include <AFMotor.h>

AF_DCMotor Lmotor(1);
AF_DCMotor Rmotor(2);

int trig = 5;
int echo = 6;
int distance;
long duration;

void setup() {

  Serial.begin(9600);
  
  Lmotor.setSpeed(150);
  Rmotor.setSpeed(150);
  Lmotor.run(RELEASE);
  Rmotor.run(RELEASE);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
 
}

void loop() {

  // - - - USING IF STATEMENT - - -
  checkDistance();

  if(distance > 20) {
    moveRobot("forward");
  }
  else {
    moveRobot("right");
    delay(500);
  }



  // - - - USING WHILE LOOP - - -
  /*
  
  while(distance>20) {
    moveRobot("forward");
    checkDistance();
  }

  moveRobot("right");
  delay(500);
   
  */

}

void checkDistance() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = 0.034 * duration / 2;

  Serial.print("Distance: "); Serial.println(distance);
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
