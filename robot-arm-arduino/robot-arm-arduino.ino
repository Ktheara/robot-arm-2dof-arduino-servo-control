#include <Servo.h>
#include "joystick.h"
#include <math.h>

bool DEBUG = true;

// Arm spec
float l[2]={8.0, 13.0};
int angle[2]={40, 40};
int min_angle[2]={5, 0};
int max_angle[2]={90,150};

// Control
float x=0.0;    //mm
float y=100.0;  //mm

Servo servo0;
Servo servo1;

Joystick stick(A11, A12);

void setup() {
  Serial.begin(115200);
  servo0.attach(6);
  servo1.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(stick.readY()>0) angle[0]++;
  else if(stick.readY()<0) angle[0]--;

  if(stick.readX()<0) angle[1]++;
  else if(stick.readX()>0) angle[1]--;
  

  // Limit servo angle
  angle[0]=constrain(angle[0], min_angle[0], max_angle[0]);
  angle[1]=constrain(angle[1], min_angle[1], max_angle[1]);

  // Signle to servo
  servo0.write(angle[0]);
  servo1.write(angle[1]);

  //--Debug--
  if(DEBUG){
    Serial.print(angle[0]);
    Serial.print(", ");
    Serial.println(angle[1]);
  }
  
  delay(20);
}
