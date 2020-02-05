#include "EnemyManager.h"

void EnemyManager::startNewLevel(){
  time = 0;
  frightenedTime = 0;
  curState = GhostsState::Scatter;
  
  blinky.startNewLevel(output);
  pinky.startNewLevel(output);
  inky.startNewLevel(output);
  clyde.startNewLevel(output);
}

void EnemyManager::update(double curX, double curY, Direction curDir,uint8_t* pointMap,int dots,int* ens){
  blinky.calculateDirection(curX, curY, curDir, pointMap);
  blinky.move(output, pointMap, ens);
}
