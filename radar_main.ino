#include <Servo.h>

#define ECHO_PIN 8
#define TRIG_PIN 7

Servo myservo;

int pos = 0;

void setup(){
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);
}
void loop(){

  for(pos = 0; pos <= 170; pos += 1){
    myservo.write(pos);
    Serial.print(pos);
    Serial.print(",");
    Serial.print(measure());
    Serial.print(";");
    delay(15);
  }
  for(pos = 170; pos >= 0; pos -= 1){
    myservo.write(pos);
    Serial.print(pos);
    Serial.print(",");
    Serial.print(measure());
    Serial.print(";");
    delay(15);
  }
}

int measure(){
  digitalWrite(TRIG_PIN, HIGH);
  digitalWrite(TRIG_PIN, LOW);

  int distance = pulseIn(ECHO_PIN, HIGH, 15000)/50;

  return constrain(distance, 1, 300);
}
