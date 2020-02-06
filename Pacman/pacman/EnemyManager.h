#pragma once
#include "Units.h"
#include "OutputManager.h"

class EnemyManager{
public:
  EnemyManager(OutputManager& om):output(om){
    timings = new long long int[8]; // чет - разбегание, нечет - преследование
    ghosts = new Enemy*[4];
    ghosts[0] = new Blinky();
    ghosts[1] = new Pinky();
    ghosts[2] = new Inky();
    ghosts[3] = new Clyde();
    
    timings[0] = 0;timings[1] = 7000;
    timings[2] = 27000;timings[3] = 34000;
    timings[4] = 54000;timings[5] = 59000;
    timings[6] = 79000;timings[7] = 84000;
  };
  Point getPosI(int8_t value) { return ghosts[value]->getPosition(); };
  void startNewLevel();
  void startFrightened(){ frightenedTime=0; frightened = true; };
  void update(double curX, double curY, Direction curDir,uint8_t* pointMap,int dots, int* ens);

  bool frightened = false;
private:
  Enemy** ghosts;
  long long int* timings;
  long long int time = 0;
  long long int frightenedTime;
  GhostsState curState = GhostsState::Scatter;
  OutputManager& output;
};
