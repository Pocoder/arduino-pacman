#pragma once
#include "Units.h"
#include "OutputManager.h"

enum class GhostsState{
  Chase,
  Scatter,
  Frightened
};

class EnemyManager{
public:
  EnemyManager(OutputManager& om):output(om),blinky(),pinky(),inky(), clyde(){};
  void startNewLevel();
  void update(double curX, double curY, Direction curDir,uint8_t* pointMap,int dots, int* ens);
  Point getBlinkyPos(){ return blinky.getPosition(); };
private:
  long long int time = 0;
  long long int frightenedTime = 0;
  GhostsState curState = GhostsState::Scatter;
  Blinky blinky;
  Pinky pinky;
  Inky inky;
  Clyde clyde;
  OutputManager& output;
};
