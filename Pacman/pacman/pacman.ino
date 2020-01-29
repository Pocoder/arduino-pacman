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

const int XP = 6, XM = A2, YP = A1, YM = 7; 
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

OutputManager OManager(&tft);
InputManager IManager(&tft, &ts);
GameManager GManager(OManager, IManager);


void setup(void) {
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  GManager.load();
}

void loop(void) {
  GManager.update();
}
