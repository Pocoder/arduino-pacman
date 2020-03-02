#include "GameManager.h"

//loading
void GameManager::load() {
  curState = State::LOADING;
  output.load();
  enterName();
}

//entering name
void GameManager::enterName() {
  curState = State::ENTERING_NAME;
  output.enterName(name, nameSize);
}
void GameManager::dealKeyboard(TSPoint p) {
  if (p.x >= 240 - 96 && p.x <= 240 - 48 && p.y >= 320 - 24) { //backspace
    name[--nameSize] ='\0';
    output.writeName(name, nameSize);
  }
  else if (p.x > 240 - 48 && p.y >= 320 - 24) { //OK
    openMenu();
  }
  else if (nameSize < 6) {
    if (p.y >= 320 - 72) { //letters
      int x = p.x / 24;
      int y = (p.y - (320 - 72)) / 24;
      char c;
      if (nameSize == 0) {
        c = 'A' + 10 * y + x;
      }
      else {
        c = 'a' + 10 * y + x;
      }
      name[nameSize++] = c;
      output.writeName(name, nameSize);
    }
  }
}

//menu
void GameManager::openMenu() {
  curState = State::MENU;
  output.loadMenu();
}
void GameManager::dealMenuButtons(TSPoint p) {
  if (p.x >= 50 && p.x <= 190) {
    if (p.y >= 110 && p.y <= 170) {
      //play
      startGame();
    }
    else if (p.y >= 185 && p.y <= 245) {
      //settings
      openSettings();
    }
  }
}

//settings
void GameManager::openSettings() {
  curState = State::SETTINGS;
  output.loadSettings();
}
void GameManager::dealSettingsButtons(TSPoint p) {
  if (p.x >= 97 && p.x<=145 && p.y>= 260 && p.y<=275){
    openMenu();
  }
  if (p.x >= 50 && p.x <= 190) {
    if (p.y >= 110 && p.y <= 170) {
      //change name
      enterName();
    }
    else if (p.y >= 185 && p.y <= 245) {
      //record table
      openRecords();
    }
  }
}

//records
void GameManager::openRecords(){
  output.loadRecords();
  curState = State::RECORDS;
}
void GameManager::dealRecordsButtons(TSPoint p){
  if (p.x >= 97 && p.x<=145 && p.y>= 260 && p.y<=275){
    openMenu();
  }
}

//game
void GameManager::startGame(){
  curState=State::IN_GAME;
  game.start();
}
void GameManager::dealGameButtons(TSPoint p){
  if (game.isGameOver()){
    gameOver(game.getPoints());
  }else{
    game.update(p);
  }
}

//gameOver
void GameManager::gameOver(int points){
  curState = State::GAME_OVER;
  int8_t place = 6;
  for (int8_t i = 5;i>=0;i--){
    if (points < eeprom_read_word(i*10+8))
      break;
    byte* m = new byte[10];
    eeprom_read_block((void*)m, 10*i, 10);
    eeprom_write_block((void*)m, 10*(i+1), 10);
    delete[] m;
    place--;
  }
  for (int8_t i = 0;i<10;i++)
    eeprom_write_byte(place*10 + i,255);
  for (int8_t i = 0;i<nameSize;i++)
    eeprom_write_byte(place*10 + i, name[i]);
    
  eeprom_write_word(place*10 + 8, points);
  output.loadGameOver();
}
void GameManager::dealGameOverButtons(TSPoint p){
  if (p.x>=50 && p.x<=190 && p.y>=130 && p.y<=190){
    openMenu();
  }
}

void GameManager::update() {
  TSPoint point = input.get();
  switch (curState) {
  case State::ENTERING_NAME:
    dealKeyboard(point);
    delay(150);
    break;
  case State::MENU:
    dealMenuButtons(point);
    delay(150);
    break;
  case State::SETTINGS:
    dealSettingsButtons(point);
    delay(150);
    break;
  case State::RECORDS:
    dealRecordsButtons(point);
    break;
  case State::IN_GAME:
    dealGameButtons(point);
    break;
  case State::GAME_OVER:
    dealGameOverButtons(point);
    break;
  }
}
