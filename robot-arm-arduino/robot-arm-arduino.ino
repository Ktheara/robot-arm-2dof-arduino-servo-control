#include <Servo.h>

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(val);
}
