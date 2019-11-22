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

OutputManager OManager(&tft);
GameManager GManager(OManager);


void setup(void) {
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  GManager.load();
  delay(1000);
}

void loop(void) {
  switch (GManager.getState()) {
  case State::LOADING:
    GManager.enterName();
    break;
  case State::ENTERING_NAME:
    break;
  case State::MENU:
    break;
  case State::SETTINGS:
    break;
  case State::RECORDS:
    break;
  case State::IN_GAME:
    break;
  case State::GAME_OVER:
    break;
  }
}
