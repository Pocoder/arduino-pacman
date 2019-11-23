#include "InputManager.h"
extern const int XP = 6, XM = A2, YP = A1, YM = 7;

InputManager::InputManager(MCUFRIEND_kbv* p, TouchScreen* tscreen) {
  tft = p;
  ts = tscreen;
}

TSPoint InputManager::get() {
  tp = (*ts).getPoint();   //tp.x, tp.y are ADC values

  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (tp.z > MINPRESSURE&& tp.z < MAXPRESSURE) {
    xpos = map(tp.x, TS_LEFT, TS_RT, 0, (*tft).width());
    ypos = map(tp.y, TS_TOP, TS_BOT, 0, (*tft).height());
    return { xpos,ypos,tp.z };
  }
  else {
    return { -20,-20,0 }; //клавиша не нажата
  }
}
