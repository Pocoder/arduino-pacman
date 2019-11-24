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
void OutputManager::enterName(MyString& name) {
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
  writeName(name);
}
void OutputManager::writeName(MyString& name) {
  (*tft).fillRect(0, 140, 240, 45, BLACK);
  (*tft).setCursor(120 - name.getSize() * 8, 150);
  (*tft).setTextColor(YELLOW);
  (*tft).setTextSize(3);
  (*tft).println(name.str());
}

//load menu
void OutputManager::loadMenu() {
  (*tft).fillScreen(BLACK);
  int16_t width = 140;
  int16_t high = 60;
  int16_t radius = 7;
  (*tft).setCursor(121 - 2 * 18, 55);
  (*tft).setTextSize(3);
  (*tft).setTextColor(YELLOW, BLACK);
  (*tft).print("MENU");
  (*tft).fillRoundRect(50, 110, width, high, radius, YELLOW);
  (*tft).fillRoundRect(50, 185, width, high, radius, YELLOW);
  (*tft).setTextSize(2);
  (*tft).setTextColor(BLACK);
  (*tft).setCursor(121 - 2 * 6 * 2, 133);
  (*tft).print("PLAY");
  (*tft).setCursor(121 - 2 * 6 * 4, 208);
  (*tft).print("Settings");
}

//load settings
void OutputManager::loadSettings() {
  //закрашиваем надпись "меню"
  (*tft).fillRect(40, 50, 150, 50, BLACK);
  int16_t width = 140;
  int16_t high = 60;
  int16_t radius = 7;
  (*tft).setCursor(121 - 4 * 6 * 3, 55);
  (*tft).setTextSize(3);
  (*tft).setTextColor(YELLOW);
  (*tft).print("SETTINGS");
  //закрашиваем надписи "play" и "settings"
  (*tft).fillRect(121 - 24, 133, 50, 15, YELLOW);
  (*tft).fillRect(121 - 48, 208, 100, 15, YELLOW);
  (*tft).setTextSize(2);
  (*tft).setTextColor(BLACK);
  (*tft).setCursor(121 - 3 * 2 * 6, 125);
  (*tft).print("Change");
  (*tft).setCursor(121 - 2 * 2 * 6, 141);
  (*tft).print("name");
  (*tft).setCursor(121 - 3 * 6 * 2, 200);
  (*tft).print("Record");
  (*tft).setCursor(121 - 5 * 6, 216);
  (*tft).print("table");

  (*tft).setCursor(121 - 2*6*2 , 260);
  (*tft).setTextSize(2);
  (*tft).setTextColor(YELLOW);
  (*tft).print("MENU");
}

//load Records
void OutputManager::loadRecords(Records* recs){
  (*tft).fillScreen(BLACK);
  (*tft).setCursor(121 - 7*9, 55);
  (*tft).setTextSize(3);
  (*tft).setTextColor(YELLOW);
  (*tft).print("RECORDS");
  (*tft).setTextSize(2);
  for (int i = 0;i<(*recs).count;i++){
    (*tft).setCursor(5, 90+20*i);
    (*tft).print((*recs).recNames[i].str());
    (*tft).setCursor(120, 90+20*i);
    (*tft).print((*recs).recResults[i]);
  }
  (*tft).setCursor(121 - 2*6*2 , 260);
  (*tft).print("MENU");
}

//load Game
void OutputManager::loadGame(){
  (*tft).fillScreen(YELLOW);
}

void OutputManager::loadGameOver(){
  (*tft).fillScreen(BLACK);
  int16_t width = 140;
  int16_t high = 60;
  int16_t radius = 7;
  (*tft).fillRoundRect(50, 130, width, high, radius, YELLOW);
  (*tft).setCursor(121 - 2*6*2, 153);
  (*tft).setTextSize(2);
  (*tft).setTextColor(BLACK);
  (*tft).print("MENU");
  
}
