#include <TouchScreen.h>
#include "OutputManager.h"
#include "Units.h"
#include "Textures.cpp"

class Game{
public:
  Game(OutputManager& om):output(om){
  }
  bool isGameOver(){
    return gameOver;
  }
  void update(TSPoint p);
  void start();
  void startNewLevel();
private:
  Direction curDir = Direction::RIGHT;
  double curX = 14;
  double curY = 27;
  int points = 0;
  int lives = 3;
  bool gameOver = false;
  OutputManager& output;
};
