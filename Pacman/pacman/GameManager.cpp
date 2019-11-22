#include "GameManager.h"

void GameManager::load() {
  curState = State::LOADING;
  output.load();
}

void GameManager::enterName() {
  curState = State::ENTERING_NAME;
  output.enterName();
}
