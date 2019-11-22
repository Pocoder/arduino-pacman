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
}

void loop(void) {

}
