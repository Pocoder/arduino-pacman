#include "OutputManager.h"
#include "Textures.cpp"

OutputManager::OutputManager(MCUFRIEND_kbv* p) {
  tft = p;
}

void OutputManager::oprint(int x, int y, char* text){
  (*tft).setCursor(x, y);
  (*tft).setTextSize(1);
  (*tft).setTextColor(YELLOW);
  (*tft).println(text);
}
void OutputManager::rect(int x, int y, int width, int height){
  (*tft).fillRect(x, y, width, height ,BLACK);
}
//loading
void OutputManager::load() {
  (*tft).fillScreen(BLACK);
  /*(*tft).setCursor(77, 85);
  (*tft).setTextColor(YELLOW);
  (*tft).setTextSize(4);
  (*tft).println("GAME");
  (*tft).setCursor(112, 114);
  (*tft).setTextSize(2);
  (*tft).println("by");
  (*tft).setCursor(4, 132);
  (*tft).setTextSize(3);
  (*tft).println("Denis Makarov");*/
  
  /*(*tft).setTextSize(2);
  (*tft).setTextColor(RED);
  (*tft).setCursor(70, 237);
  (*tft).println("P");
  (*tft).setTextColor(0xFCE0);
  (*tft).setCursor(90, 237);
  (*tft).println("A");
  (*tft).setTextColor(YELLOW);
  (*tft).setCursor(110, 237);
  (*tft).println("C");
  (*tft).setTextColor(GREEN);
  (*tft).setCursor(130, 237);
  (*tft).println("M");
  (*tft).setTextColor(BLUE);
  (*tft).setCursor(150, 237);
  (*tft).println("A");
  (*tft).setTextColor(MAGENTA);
  (*tft).setCursor(170, 237);
  (*tft).println("N");
  int curTexture = 0;
  Direction curDir = Direction::RIGHT;
  for (int i = 0; i < 160; i+=4) {
    refreshPacman(34+i,240,38+i,240, curTexture,curDir);
    ++curTexture %= 4;
    delay(80);
  }*/
}

//entering name
void OutputManager::enterName(char* name,int8_t nameSize) {
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
  (*tft).setTextSize(2);
  for (int16_t h = high; h <= 320 - 24; h += 24) {
    for (int16_t w = 0; w <= 240 - 24; w += 24) {
      (*tft).setCursor(w + 7, h + 4);
      (*tft).print(c);
      c++;
    }
  }
  int16_t w = 240 - 96;
  int16_t h = 320 - 24;
  (*tft).fillRect(w, h, BOXSIZE * 2, BOXSIZE, BLACK);
  (*tft).setCursor(w + 13, h + 5);
  (*tft).print("<-");
  w += 48;
  (*tft).fillRect(w, h, BOXSIZE * 2, BOXSIZE, BLACK);
  //(*tft).drawRect(w, h, BOXSIZE*2, BOXSIZE, 0x7777);
  (*tft).setCursor(w + 13, h + 5);
  (*tft).print("OK");
  writeName(name, nameSize);
}
void OutputManager::writeName(char* name,int8_t nameSize) {
  (*tft).fillRect(0, 140, 240, 45, BLACK);
  (*tft).setCursor(120 - nameSize * 8, 150);
  (*tft).setTextColor(YELLOW);
  (*tft).setTextSize(3);
  (*tft).println(name);
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
  //закрашиваем надписи "play" и "settings" и
  (*tft).fillRect(121 - 24, 133, 50, 17, YELLOW);
  (*tft).fillRect(121 - 48, 208, 100, 17, YELLOW);
  (*tft).setTextSize(2);
  (*tft).setCursor(121 - 2*6*2 , 260);
  (*tft).print("MENU");
  
  (*tft).setTextColor(BLACK);
  (*tft).setCursor(121 - 3 * 2 * 6, 125);
  (*tft).print("Change");
  (*tft).setCursor(121 - 2 * 2 * 6, 141);
  (*tft).print("name");
  (*tft).setCursor(121 - 3 * 6 * 2, 200);
  (*tft).print("Record");
  (*tft).setCursor(121 - 5 * 6, 216);
  (*tft).print("table");
}

//load Records
void OutputManager::loadRecords(){
  (*tft).fillScreen(BLACK);
  (*tft).setCursor(121 - 7*9, 55);
  (*tft).setTextSize(3);
  (*tft).setTextColor(YELLOW);
  (*tft).print("RECORDS");
  (*tft).setTextSize(2);

  int* res = new int[6];
  for (int8_t i = 0;i<6;i++){
    if (eeprom_read_byte(i*10)==255)
      break;
    res[i] = eeprom_read_word(i*10+8);
    (*tft).setCursor(120, 120+20*i);
    (*tft).print(res[i]);
  }
  delete[] res;
  
  (*tft).setCursor(121 - 2*6*2 , 260);
  (*tft).print("MENU");
}

//Game
bool isPoint(int8_t x, int8_t y){
  int8_t num = 5*x + y/8;
  int8_t mask = 1<<(7-y%8);
  return pointsMap[num] & mask;
}

void OutputManager::loadGame(){
  
  (*tft).fillScreen(BLACK);
  //ramka
  /*
  (*tft).drawFastVLine(8, 32, 247, BLUE);
  (*tft).drawFastVLine(10, 34, 243, BLUE);
  (*tft).drawFastVLine(229, 34, 243, BLUE);
  (*tft).drawFastVLine(231, 32, 247, BLUE);
  (*tft).drawFastHLine(8, 32, 223, BLUE);
  (*tft).drawFastHLine(10, 34, 219, BLUE);
  (*tft).drawFastHLine(10, 277, 219, BLUE);
  (*tft).drawFastHLine(8, 279,223, BLUE);
  */
  
  int radius = 3;
  (*tft).drawRoundRect(117, 34, 5, 32,radius, BLUE); // верхний центральный
  (*tft).drawRoundRect(8, 109, 42, 29,radius, BLUE); //левый верхний
  (*tft).drawRoundRect(8, 157, 42, 29,radius, BLUE); // левый центральный
  (*tft).drawRoundRect(8, 229, 21, 5,radius, BLUE); // левый нижний
  (*tft).drawRoundRect(189, 109, 42, 29,radius, BLUE); // првый вехрний
  (*tft).drawRoundRect(189, 157, 42, 29,radius, BLUE); // правый центральный
  (*tft).drawRoundRect(211, 229, 21, 5,radius, BLUE); // правый нижний
  //(*tft).fillRect(8, 139, 6,17 ,BLACK);
  //(*tft).fillRect(225, 139, 7, 17,BLACK);
  
  //top rectangles
  (*tft).drawRoundRect(29, 53, 21, 13,radius, BLUE);
  (*tft).drawRoundRect(69, 53, 29, 13,radius, BLUE);
  (*tft).drawRoundRect(141, 53, 29, 13,radius, BLUE);
  (*tft).drawRoundRect(189, 53, 21, 13,radius, BLUE);
  (*tft).drawRoundRect(29, 85, 21, 5,radius, BLUE);
  (*tft).drawRoundRect(189, 85, 21, 5,radius, BLUE);  
  //top mnogogranniki
  (*tft).drawRoundRect(69, 85, 5, 53,radius, BLUE);
  (*tft).drawRoundRect(72, 109, 26, 5, radius, BLUE);
  (*tft).drawRoundRect(93, 85, 53, 5,radius, BLUE);
  (*tft).drawRoundRect(117, 88, 5, 26,radius, BLUE);
  (*tft).drawRoundRect(165, 85, 5, 53,radius, BLUE);
  (*tft).drawRoundRect(141, 109, 26, 5,radius, BLUE); 
     //
  //(*tft).fillRect(70, 110, 6, 3,BLACK);
  //(*tft).fillRect(118, 88, 3, 5,BLACK);
  //(*tft).fillRect(164, 110, 5, 3,BLACK); 

  //prison

  (*tft).drawFastVLine(91, 133, 31, WHITE);
  (*tft).drawFastVLine(148, 133, 31, WHITE);
  (*tft).drawFastHLine(91, 133, 57, WHITE);
  //(*tft).drawFastHLine(131, 133,17, WHITE);
  (*tft).drawFastHLine(91, 163, 57, WHITE);
  
  //bot monogogranniki
  (*tft).drawRoundRect(69, 157, 5, 29,radius, BLUE); 
  (*tft).drawRoundRect(165, 157, 5, 29,radius, BLUE); 
  (*tft).drawRoundRect(69, 205, 29,  5,radius, BLUE); 
  (*tft).drawRoundRect(141, 205, 29, 5,radius, BLUE); 

  (*tft).drawRoundRect(29, 205, 21, 5,radius, BLUE);
  (*tft).drawRoundRect(189, 205, 21, 5,radius, BLUE);
  (*tft).drawRoundRect(93, 181, 53, 5,radius, BLUE);
  (*tft).drawRoundRect(93, 229, 53, 5,radius, BLUE);
  (*tft).drawRoundRect(29, 253, 69, 5,radius, BLUE);
  (*tft).drawRoundRect(141, 253, 69, 5,radius, BLUE);
  
  (*tft).drawRoundRect(45, 205, 5, 29,radius, BLUE);
  (*tft).drawRoundRect(189, 205, 5, 29,radius, BLUE);
  (*tft).drawRoundRect(117, 181, 5, 29,radius, BLUE);
  (*tft).drawRoundRect(117, 229, 5, 29,radius, BLUE);
  (*tft).drawRoundRect(69, 229, 5, 29,radius, BLUE);
  (*tft).drawRoundRect(165, 229, 5, 29,radius, BLUE);
  
}

void OutputManager::loadStats(int points, int8_t lives, int* energ){
  for (int8_t j = 0;j<40;j++){
    for (int8_t i = 0;i<15;i++){
      int x = 8*i+3;
      int y = 8*j+3;
      if (isPoint(i,j)){
        (*tft).fillRect(x, y,2,2, WHITE);
        (*tft).fillRect(238-x, y,2,2, WHITE);
      }
    }
  }
  for (int i=0;i<4;i++){
    (*tft).fillCircle(((energ[i]>>8) * 8)+3,(((energ[i]<<8)>>8) * 8)+3, 2, WHITE);
  }

  //pacman
  (*tft).drawBitmap(8*14, 8*27-4, pacman1R,16,16, YELLOW);

  (*tft).setCursor(10, 290);
  (*tft).setTextSize(2);
  (*tft).setTextColor(YELLOW);
  (*tft).print("SCORE");

  (*tft).setCursor(90, 290);
  (*tft).print(points);
  refreshLives(lives);
}

void OutputManager::refreshPacman(int oldX,int oldY, int newX,int newY, int8_t curTexture, Direction curDir){
  (*tft).drawBitmap(oldX-4, oldY-4, pacman3,16,16, BLACK);
  (*tft).drawBitmap(newX-4, newY-4, pacman3,16,16, YELLOW);
  /*if (curTexture == 0){
    switch (curDir){
      case Direction::RIGHT:
        (*tft).drawBitmap(newX-4, newY-4, pacman2R,16,16, YELLOW);
        break;
      case Direction::LEFT:
        (*tft).drawBitmap(newX-4, newY-4, pacman2L,16,16, YELLOW);
        break;
      case Direction::TOP:
        (*tft).drawBitmap(newX-4, newY-4, pacman2T,16,16, YELLOW);
        break;
      case Direction::DOWN:
        (*tft).drawBitmap(newX-4, newY-4, pacman2D,16,16, YELLOW);
        break;
    }
  }
  if (curTexture == 1){
    switch (curDir){
      case Direction::RIGHT:
        (*tft).drawBitmap(newX-4, newY-4, pacman3,16,16, YELLOW);
        break;
      case Direction::LEFT:
        (*tft).drawBitmap(newX-4, newY-4, pacman3,16,16, YELLOW);
        break;
      case Direction::TOP:
        (*tft).drawBitmap(newX-4, newY-4, pacman3,16,16, YELLOW);
        break;
      case Direction::DOWN:
        (*tft).drawBitmap(newX-4, newY-4, pacman3,16,16, YELLOW);
        break;
    }
  }
  if (curTexture == 2){
    switch (curDir){
      case Direction::RIGHT:
        (*tft).drawBitmap(newX-4, newY-4, pacman2R,16,16, YELLOW);
        break;
      case Direction::LEFT:
        (*tft).drawBitmap(newX-4, newY-4, pacman2L,16,16, YELLOW);
        break;
      case Direction::TOP:
        (*tft).drawBitmap(newX-4, newY-4, pacman2T,16,16, YELLOW);
        break;
      case Direction::DOWN:
        (*tft).drawBitmap(newX-4, newY-4, pacman2D,16,16, YELLOW);
        break;
    }
  }
  if (curTexture == 3){
    switch (curDir){
      case Direction::RIGHT:
        (*tft).drawBitmap(newX-4, newY-4, pacman1R,16,16, YELLOW);
        break;
      case Direction::LEFT:
        (*tft).drawBitmap(newX-4, newY-4, pacman1L,16,16, YELLOW);
        break;
      case Direction::TOP:
        (*tft).drawBitmap(newX-4, newY-4, pacman1T,16,16, YELLOW);
        break;
      case Direction::DOWN:
        (*tft).drawBitmap(newX-4, newY-4, pacman1D,16,16, YELLOW);
        break;
    }
  }*/
}

void OutputManager::refreshGhost(int oldX,int oldY, int newX,int newY, int color, bool eyeMode){
  (*tft).drawBitmap(oldX-4, oldY-4, ghostTexture, 16,16, BLACK);
  (*tft).drawBitmap(oldX-4, oldY+1, ghostEyes, 16,5, BLACK);

  if (!eyeMode)
    (*tft).drawBitmap(newX-4, newY-4, ghostTexture,16,16, color);
  (*tft).drawBitmap(newX-4, newY+1, ghostEyes, 16,5, WHITE);
}

void OutputManager::refreshPoints(int value){
  (*tft).fillRect(90, 290, 80, 25 ,BLACK);
  (*tft).setTextSize(2);
  (*tft).setCursor(90, 290);
  (*tft).print(value);
}
void OutputManager::refreshLives(int8_t lives){
  (*tft).fillRect(180, 290, 59, 20 ,BLACK);
  if (lives>=1)
    (*tft).drawBitmap(180,290 , pacman1R,16,16, YELLOW);
  if (lives>=2)
    (*tft).drawBitmap(200,290 , pacman1R,16,16, YELLOW);
  if (lives>=3)  
    (*tft).drawBitmap(220,290 , pacman1R,16,16, YELLOW);
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

void OutputManager::refreshDot(uint8_t x,uint8_t y){
  (*tft).fillRect(8*x+3, 8*y+3,2,2, WHITE);
}

void OutputManager::drawBigPoint(uint8_t x,uint8_t y){
  (*tft).fillCircle(x+3,y+3, 2, WHITE);
}
