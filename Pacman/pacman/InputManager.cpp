#include "InputManager.h"

InputManager::InputManager(MCUFRIEND_kbv* p) {
  tft = p;
  ts = TouchScreen(XP, YP, XM, YM, 300);
}

TSPoint InputManager::getPoint() {
  tp = ts.getPoint();   //tp.x, tp.y are ADC values

  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (tp.z > MINPRESSURE&& tp.z < MAXPRESSURE) {
    xpos = map(tp.x, TS_LEFT, TS_RT, 0, (*tft).width());
    ypos = map(tp.y, TS_TOP, TS_BOT, 0, (*tft).height());
  }
  return TSPoint{xpos,ypos,tp.z};
}
