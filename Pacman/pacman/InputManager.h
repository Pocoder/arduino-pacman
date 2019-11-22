#pragma once
#include <TouchScreen.h>
#include "Adafruit_GFX.h"
#include <MCUFRIEND_kbv.h>

#define MINPRESSURE 200
#define MAXPRESSURE 1000



class InputManager {
public:
  InputManager(MCUFRIEND_kbv* p);
  TSPoint getPoint();
private:
  const int XP = 6, XM = A2, YP = A1, YM = 7; //ID=0x9341
  const int TS_LEFT = 919, TS_RT = 194, TS_TOP = 185, TS_BOT = 915; //Calibrated
  MCUFRIEND_kbv* tft;
  TouchScreen ts;
  TSPoint tp;
  int16_t xpos, ypos; //screen coordinates
};
