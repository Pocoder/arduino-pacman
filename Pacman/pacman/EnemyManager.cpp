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
  if (frightened){
    frightenedTime+=30;
    blinky.frightened();
    pinky.frightened();
    if (frightenedTime >= 5000)
      frightened = false;
  } else {
    time+=30;
    int j = 0;
    for (int i = 0;i<8;i++){
      if (time>=timings[i])
        j = i;
    }
    if (j % 2){
      blinky.chase();
      pinky.chase();
    }
    else{
      blinky.scatter();
      pinky.scatter();
    }
  }
  blinky.calculateDirection(curX, curY, curDir, pointMap);
  blinky.move(output, pointMap, ens, dots);
  pinky.calculateDirection(curX, curY, curDir, pointMap);
  pinky.move(output, pointMap, ens, dots);
}
