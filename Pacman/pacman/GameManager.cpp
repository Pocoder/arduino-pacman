#include "GameManager.h"

//loading
void GameManager::load() {
  curState = State::LOADING;
  output.load();
}

//entering name
void GameManager::enterName() {
  output.enterName();
}
void GameManager::dealKeyboard(TSPoint p) {
  if (p.x >= 240 - 96 && p.x <= 240 - 48 && p.y >= 320 - 24) { //backspace
    name.backspace();
    output.writeName(name);
  }
  else if (p.x > 240 - 48 && p.y >= 320 - 24) { //OK
    curState = State::MENU;
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

void GameManager::update() {
  if (curState == State::LOADING) {
    curState = State::ENTERING_NAME;
    enterName();
  }
  else {
    TSPoint point = input.get();
    switch (curState) {
    case State::ENTERING_NAME:
      dealKeyboard(point);
      delay(130);
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
}
