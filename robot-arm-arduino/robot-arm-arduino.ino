#include <Servo.h>
#include "joystick.h"
#include <math.h>

bool DEBUG = true;

// Arm spec

int angle[2] = {40, 40};
int min_angle[2] = {5, 0};
int max_angle[2] = {90, 150};

// Control mm
double L1 = 80.0;
double L2 = 130.0;
double x = 100.0;
double y = 100.0;

double L3=0.0;
double alpha1 = 0.0;
double alpha2 = 0.0;
double alpha3 = 0.0;
double theta = 0.0;

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

  L3 = sqrt(sq(x) + sq(y)); // Distance from Origin to P(x,y)
  alpha1 = atan(y / x);
  alpha2 = acos((sq(L1)+sq(L3)-sq(L2)) / (2.0*L1*L3))*(double)(180.0/PI);
  alpha3 = acos((sq(L1)+sq(L2)-sq(L3)) / (2.0*L1*L2))*(double)(180.0/PI);
  theta = (asin(y/L3))*(double)(180.0/PI);

  angle[0] = round(alpha2 + theta);
  angle[1] = round(alpha3);
  angle[0] = constrain(angle[0], min_angle[0], max_angle[0]);
  angle[1] = constrain(angle[1], min_angle[1], max_angle[1]);

  // Joystick
  if (stick.readY() > 0) y++;
  else if (stick.readY() < 0) y--;
  y = constrain(y, 0, 200);

  if (stick.readX() < 0) x++;
  else if (stick.readX() > 0) x--;
  x = constrain(x, 60, 200);
  // Limit servo angle
  

  // Signle to servo
  servo0.write(angle[0]);
  servo1.write(angle[1]);

  //--Debug--
  if (DEBUG) {
    Serial.print("x: ");
    Serial.print(x);
    Serial.print(" | y: ");
    Serial.print(y);
    Serial.print(" | angle2: ");
    Serial.print(angle[0]);
    Serial.print(" | angle2: ");
    Serial.println(angle[1]);
  }

  delay(20);
}


double sqre(double a){
  return a*a;
}
