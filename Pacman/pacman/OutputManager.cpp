#include "OutputManager.h"

OutputManager::OutputManager(MCUFRIEND_kbv* p) {
  tft = p;
}

void OutputManager::load() {
  (*tft).fillScreen(BLACK);
  (*tft).setCursor(53, 100);
  (*tft).setTextColor(YELLOW); 
  (*tft).setTextSize(4);
  (*tft).println("PACMAN");
  (*tft).fillCircle(60,200,17,YELLOW);
  for (int i = 0;i<120;i++){
    (*tft).fillCircle(60+i,200,17,BLACK);
    (*tft).fillCircle(61+i,200,17,YELLOW);
    (*tft).fillCircle(64+i,188,2,BLACK);
    (*tft).fillTriangle(80+i,180, 60+i,200,80+i,220,BLACK);
    delay(3);
  }
}
