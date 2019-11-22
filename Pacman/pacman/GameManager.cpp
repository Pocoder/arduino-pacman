#include "GameManager.h"

void GameManager::load() {
  curState = State::LOADING;
  output.load();
}

void GameManager::enterName() {
  curState = State::ENTERING_NAME;
  output.enterName();
}

void GameManager::update() {
  if (curState == State::LOADING) {
    curState = State::ENTERING_NAME;
    enterName();
  }
  else {
    TSPoint point = input.getPoint();
    switch (curState) {
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
}
