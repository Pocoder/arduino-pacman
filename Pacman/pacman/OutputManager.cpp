#include "OutputManager.h"
#include "Textures.cpp"

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
  (*tft).drawBitmap(60 , 200, pacman1,16,16, YELLOW);
  for (int i = 0; i < 120; i++) {
    (*tft).drawBitmap(60+i , 200, pacman1,16,16, BLACK);
    (*tft).drawBitmap(61 + i, 200, pacman1,16,16, YELLOW);
    
    delay(5);
  }
}

//entering name
void OutputManager::enterName(MyString& name) {
  (*tft).fillScreen(BLACK);
  (*tft).drawBitmap(0,0, pacman1, 16,16,YELLOW);
  (*tft).drawBitmap(32,0, pacman2, 16,16,YELLOW);
  (*tft).drawBitmap(65,0, pacman3, 16,16,YELLOW);
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
  (*tft).fillRect(121 - 24, 133, 50, 17, YELLOW);
  (*tft).fillRect(121 - 48, 208, 100, 17, YELLOW);
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

//Game
void OutputManager::loadGame(){
  (*tft).fillScreen(BLACK);
  //ramka
  (*tft).drawFastVLine(8, 32, 247, BLUE);
  (*tft).drawFastVLine(10, 34, 243, BLUE);
  (*tft).drawFastVLine(229, 34, 243, BLUE);
  (*tft).drawFastVLine(231, 32, 247, BLUE);
  (*tft).drawFastHLine(8, 32, 223, BLUE);
  (*tft).drawFastHLine(10, 34, 219, BLUE);
  (*tft).drawFastHLine(10, 277, 219, BLUE);
  (*tft).drawFastHLine(8, 279,223, BLUE);

  int radius = 3;
  (*tft).drawRoundRect(117, 34, 5, 32,radius, BLUE); // верхний центральный
  (*tft).drawRoundRect(8, 109, 42, 29,radius, BLUE); //левый верхний
  (*tft).drawRoundRect(8, 157, 42, 29,radius, BLUE); // левый центральный
  (*tft).drawRoundRect(8, 229, 21, 5,radius, BLUE); // левый нижний
  (*tft).drawRoundRect(189, 109, 42, 29,radius, BLUE); // првый вехрний
  (*tft).drawRoundRect(189, 157, 42, 29,radius, BLUE); // правый центральный
  (*tft).drawRoundRect(210, 229, 21, 5,radius, BLUE); // правый нижний
  (*tft).fillRect(8, 139, 6,17 ,BLACK);
  (*tft).fillRect(225, 139, 7, 17,BLACK);
  
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
  (*tft).fillRect(70, 110, 6, 3,BLACK);
  (*tft).fillRect(118, 88, 3, 5,BLACK);
  (*tft).fillRect(164, 110, 5, 3,BLACK); 

  //prison
  (*tft).drawRect(93, 133, 21, 3, WHITE);
  (*tft).drawRect(93, 133, 3, 26, WHITE);
  (*tft).drawRect(93, 157, 53, 3, WHITE);
  (*tft).drawRect(125, 133, 21, 3, WHITE);
  (*tft).drawRect(144, 133, 3, 26, WHITE);

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

  for (int j = 0;j<40;j++){
    for (int i = 0;i<15;i++){
      int x = 8*i+3;
      int y = 8*j+3;
      if (pacmanMap[i][j]==2){
        
        (*tft).fillRect(x, y,2,2, WHITE);
        (*tft).fillRect(238-x, y,2,2, WHITE);
      } else
      if (pacmanMap[i][j]==3){
        (*tft).fillCircle(19, y, 2, WHITE);
        (*tft).fillCircle(219, y, 2, WHITE);
      }
    }
  }

  //pacman
  (*tft).drawBitmap(8*14-4, 8*27-4, pacman3,16,16, YELLOW);

  (*tft).setCursor(10, 290);
  (*tft).setTextSize(2);
  (*tft).setTextColor(YELLOW);
  (*tft).print("Points");

  (*tft).setCursor(90, 290);
  (*tft).print("0");

  (*tft).drawBitmap(180,290 , pacman1,16,16, YELLOW);
  (*tft).drawBitmap(200,290 , pacman1,16,16, YELLOW);
  (*tft).drawBitmap(220,290 , pacman1,16,16, YELLOW);
}

void OutputManager::refreshPacman(int oldX,int oldY, int newX,int newY){
  (*tft).drawBitmap(oldX-4, oldY-4, pacman3,16,16, BLACK);
  (*tft).drawBitmap(newX-4, newY-4, pacman3,16,16, YELLOW);
}

void OutputManager::refreshPoints(int value){
  (*tft).fillRect(90, 290, 80, 25 ,BLACK);
  (*tft).setTextSize(2);
  (*tft).setCursor(90, 290);
  (*tft).print(value);
}

void OutputManager::refreshLives(int value){
  if (value == 2)
    (*tft).fillRect(220, 290, 16,16 ,BLACK);
  if (value == 1)
    (*tft).fillRect(200, 290, 16,16 ,BLACK);
  if (value == 0)
    (*tft).fillRect(180, 290, 16,16 ,BLACK);
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
