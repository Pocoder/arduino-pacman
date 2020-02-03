#include <TouchScreen.h>
#include "OutputManager.h"
#include "Units.h"
#include "Textures.cpp"

class Game{
public:
  Game(OutputManager& om):output(om){
    curPointsMap = new uint8_t[150];
  }
  bool isGameOver(){
    return gameOver;
  }
  void update(TSPoint p);
  void start();
  void startNewLevel();
private:
  uint8_t* curPointsMap;
  bool isPoint(uint8_t x, uint8_t y){
    uint8_t num = 5*x + y/8;
    uint8_t mask = 1<<(7-y%8);
    return curPointsMap[num] & mask;
  }
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
  
  bool BPoint1 = true;
  bool BPoint2 = true;
  bool BPoint3 = true;
  bool BPoint4 = true;
  OutputManager& output;
};
