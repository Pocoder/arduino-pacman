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
  output.enterName(name);
}
void GameManager::dealKeyboard(TSPoint p) {
  if (p.x >= 240 - 96 && p.x <= 240 - 48 && p.y >= 320 - 24) { //backspace
    name.backspace();
    output.writeName(name);
  }
  else if (p.x > 240 - 48 && p.y >= 320 - 24) { //OK
    openMenu();
  }
  else if (name.getSize() < 6) {
    if (p.y >= 320 - 72) { //letters
      int x = p.x / 24;
      int y = (p.y - (320 - 72)) / 24;
      char c;
      if (name.getSize() == 0) {
        c = 'A' + 10 * y + x;
      }
      else {
        c = 'a' + 10 * y + x;
      }
      name.push(c);
      output.writeName(name);
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
      //startGame();
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
  curState = State::RECORDS;
  output.loadRecords(&recs);
}
void GameManager::dealRecordsButtons(TSPoint p){
  if (p.x >= 97 && p.x<=145 && p.y>= 260 && p.y<=275){
    openMenu();
  }
}

void GameManager::update() {
  TSPoint point = input.get();
  switch (curState) {
  case State::ENTERING_NAME:
    dealKeyboard(point);
    delay(130);
    break;
  case State::MENU:
    dealMenuButtons(point);
    break;
  case State::SETTINGS:
    dealSettingsButtons(point);
    break;
  case State::RECORDS:
    dealRecordsButtons(point);
    break;
  case State::IN_GAME:
    break;
  case State::GAME_OVER:
    break;
  }
}
