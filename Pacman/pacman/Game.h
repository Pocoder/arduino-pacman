#include <TouchScreen.h>
#include "OutputManager.h"

class Game{
public:
  Game(OutputManager& om):output(om){
  }
  bool isGameOver(){
    return gameOver;
  }
  void update(TSPoint p){
    delay(100000);
    gameOver = true;
  }
  void start(){
    gameOver = false;
  }
private:
  bool gameOver = false;
  OutputManager& output;
};
