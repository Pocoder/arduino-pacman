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
    delay(2000);
    gameOver = true;
  }
private:
  bool gameOver = false;
  OutputManager& output;
};
