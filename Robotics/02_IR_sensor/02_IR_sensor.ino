int value;
int analogPin = 1;

void setup() {

  Serial.begin(9600);
 
}

void loop() {

  value = analogRead(analogPin);

  if(value > 800) {
    Serial.println("detecting IR: TRUE");
  }
  else {
    Serial.println("detecting IR: FALSE");
  }

}
