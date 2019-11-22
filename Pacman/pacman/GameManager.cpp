#include "GameManager.h"

void GameManager::load() {
  curState = State::LOADING;
  output.load();
  delay(3000);
  enterName();
}
