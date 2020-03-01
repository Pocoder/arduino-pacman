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
  int8_t curTexture;
  bool trouble = false;
  Direction curDir;
  Direction prevDir;
  double curX;
  double curY;
  int points;
  uint8_t lives;
  uint8_t dots;
  bool gameOver;

  int* ens;
  int* ensStart;

  OutputManager& output;
  
  void moveFunc(Direction dir);
  
  void countdown(){
    for (int i = 3;i>=1;i--){
      char* a = new char[2];
      a[0] = i+'0';
      a[1] = '\0';
      output.oprint(117,167, a);
      //delete[] a;
      delay(1000);
      output.rect(80,165,80,10);
    }
    output.oprint(114,167, "GO");
    delay(200);
    output.rect(80,165,80,12);
  }
  void deathCheck(){
    for (int8_t i = 0;i<4;i++)
      if (int(EManager.getPosI(i).x +0.5) == int(curX+0.5) && int(EManager.getPosI(i).y+0.5) == int(curY+0.5)){
        if (!EManager.frightened)
          death();
        else{
          EManager.kill(i);
          points += 200;
          output.refreshPoints(points);
        }
      }
  }
  void moveOptimisation(float arg1,float arg2,float arg3,float arg4,float deltaX,float deltaY,Direction dir ){
    if (!isBorder(char(curX+arg1),char(curY+arg2)) && !isBorder(char(curX+arg3),char(curY+arg4))){
        output.refreshPacman(8*curX,8*curY,8*(curX+deltaX),8*(curY+deltaY), curTexture, dir);
        curX+=deltaX;
        curY+=deltaY;
        trouble = false;
      } else
        trouble = true;
  }
  void refr();
};
