int trig = 5;
int echo = 6;
int distance;
long duration;

void setup() {

  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
}

void loop() {

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = 0.034 * duration / 2;

  Serial.print("Distance: "); Serial.println(distance);

}
