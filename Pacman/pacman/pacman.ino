#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

#include "Adafruit_GFX.h"
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;

#include "GameManager.h"
#include "OutputManager.h"
#include "InputManager.h"

OutputManager OManager(&tft);
InputManager IManager(&tft);
GameManager GManager(OManager, IManager);

void setup(void) {
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  GManager.load();
  delay(1000);
}

void loop(void) {
  //if (GManager.getState() == State::LOADING) {
  //  GManager.enterName();
  //}
  //int16_t xpos, ypos;  //screen coordinates
  //tp = ts.getPoint();   //tp.x, tp.y are ADC values
  //
  //pinMode(XM, OUTPUT);
  //pinMode(YP, OUTPUT);
  //if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
  //  xpos = map(tp.x, TS_LEFT, TS_RT, 0, tft.width());
  //  ypos = map(tp.y, TS_TOP, TS_BOT, 0, tft.height());
  //}
  GManager.update();
}
