#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "Arduino.h"
#include <math.h>

class Joystick{
  public:
    Joystick(int x_pin, int y_pin):Xpin(x_pin), Ypin(y_pin){}
    int readX(){
      Xval = analogRead(Xpin)-512;
      if(abs(Xval)<=20) Xval=0;
      return Xval;
    }

    int readY(){
      Yval = analogRead(Ypin)-512;
      if(abs(Yval)<=20) Yval=0;
      return Yval;
    }
    
  private:
    int Xpin;
    int Ypin;
    int Xval;
    int Yval;
};

#endif
