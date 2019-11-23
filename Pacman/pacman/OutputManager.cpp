#include "OutputManager.h"

OutputManager::OutputManager(MCUFRIEND_kbv* p) {
  tft = p;
}


//loading
void OutputManager::load() {
  (*tft).fillScreen(BLACK);
  (*tft).setCursor(53, 100);
  (*tft).setTextColor(YELLOW);
  (*tft).setTextSize(4);
  (*tft).println("PACMAN");
  (*tft).fillCircle(60, 200, 17, YELLOW);
  for (int i = 0; i < 120; i++) {
    (*tft).fillCircle(60 + i, 200, 17, BLACK);
    (*tft).fillCircle(61 + i, 200, 17, YELLOW);
    (*tft).fillCircle(64 + i, 188, 2, BLACK);
    (*tft).fillTriangle(80 + i, 180, 60 + i, 200, 80 + i, 220, BLACK);
    delay(3);
  }
}

//entering name
void OutputManager::enterName() {
  (*tft).fillScreen(BLACK);
  (*tft).setCursor(83, 70);
  (*tft).setTextColor(YELLOW);
  (*tft).setTextSize(3);
  (*tft).println("ENTER");
  (*tft).setCursor(46, 94);
  (*tft).println("YOUR NAME");
  int16_t BOXSIZE = 24;
  int16_t high = 320 - 72;
  char c = 'a';
  for (int16_t h = high; h <= 320 - 24; h += 24) {
    for (int16_t w = 0; w <= 240 - 24; w += 24) {
      (*tft).setCursor(w + 7, h + 4);
      (*tft).setTextSize(2);
      (*tft).setTextColor(YELLOW);
      (*tft).print(c);
      c++;
    }
  }
  int16_t w = 240 - 96;
  int16_t h = 320 - 24;
  (*tft).fillRect(w, h, BOXSIZE * 2, BOXSIZE, BLACK);
  (*tft).setCursor(w + 13, h + 5);
  (*tft).setTextSize(2);
  (*tft).setTextColor(YELLOW);
  (*tft).print("<-");
  w += 48;
  (*tft).fillRect(w, h, BOXSIZE * 2, BOXSIZE, BLACK);
  //(*tft).drawRect(w, h, BOXSIZE*2, BOXSIZE, 0x7777);
  (*tft).setCursor(w + 13, h + 5);
  (*tft).setTextSize(2);
  (*tft).setTextColor(YELLOW);
  (*tft).print("OK");
}
void OutputManager::writeName(MyString& name) {
  (*tft).fillRect(0, 140, 240, 30, BLACK);
  (*tft).setCursor(120 - name.getSize() * 8, 150);
  (*tft).setTextColor(YELLOW);
  (*tft).setTextSize(3);
  char* res = name.str();
  (*tft).println(res);
  delete[] res;
}
