#pragma once
#include <TouchScreen.h>
#include "OutputManager.h"
#include "Textures.cpp"
#include "EnemyManager.h"


class Game{
public:
  Game(OutputManager& om):output(om), EManager(om){
    curPointsMap = new uint8_t[150];
    ens = new int[4];
    ensStart = new int[4];
    ensStart[0] = (2<<8) + 7;
    ensStart[1] = (2<<8) + 27;
    ensStart[2] = (27<<8) + 7;
    ensStart[3] = (27<<8) + 27;
  }
  bool isGameOver(){
    return gameOver;
  }
  void update(TSPoint p);
  void start();
  void death();
  void startNewLevel();
private:
  EnemyManager EManager;
  uint8_t* curPointsMap;
  int8_t curTexture = 0;
  bool trouble = false;
  Direction curDir = Direction::RIGHT;
  Direction prevDir = Direction::RIGHT;
  double curX = 14.5;
  double curY = 27;
  int points = 0;
  uint8_t lives = 3;
  uint8_t dots = 244;
  bool gameOver = false;

  int* ens;
  int* ensStart;

  OutputManager& output;
  
  void moveFunc(Direction dir,double&, double&);
  
  void account(){
    for (int i = 1;i<=3;i++){
      char* a = new char[2];
      a[0] = i+'0';
      a[1] = '\0';
      output.oprint(117,167, a);
      //delete[] a;
      delay(1000);
      output.rect(80,163,80,10);
    }
    
    output.oprint(114,167, "GO");
    delay(200);
    output.rect(80,163,80,14);
  }
  void refr();
};
