#include "EnemyManager.h"


void EnemyManager::startNewLevel(){
  time = 0;
  frightenedTime = 0;
  curState = GhostsState::Scatter;

  for (int i =0;i<4;i++)
    ghosts[i]->startNewLevel(output);
}

void EnemyManager::kill(int8_t i){
  ghosts[i]->killed(output); 
}

void EnemyManager::update(double curX, double curY, Direction curDir,uint8_t* pointMap,int dots,int* ens){
  if (frightened){
    frightenedTime+=30;
    if (frightenedTime >= 5000){
      frightened = false;
      frightenedTime = 0;
      for (int8_t i=0;i<4;i++)
        ghosts[i]->revive(output);
    }
  } else {
    time+=30;
    int j = 0;
    for (int i = 0;i<8;i++){
      if (time>=timings[i])
        j = i;
    }
    if (j % 2){
      for (int i = 0;i<4;i++)
        ghosts[i]->chase();
    }
    else{
      for (int i = 0;i<4;i++)
        ghosts[i]->scatter();
    }
  }
  for (int i = 0;i<4;i++){
      ghosts[i]->calculateDirection(curX, curY, curDir, pointMap);
      ghosts[i]->move(output, pointMap, dots);
  }
  for (int i=0;i<4;i++){
    if (ens[i]!=0)
      output.drawBigPoint((ens[i]>>8)*8,((ens[i]<<8)>>8)*8);
  }
}
