#include <TouchScreen.h>

class Game{
public:
  bool isGameOver(){
    return gameOver;
  }
  void update(TSPoint p){
    delay(2000);
    gameOver = true;
  }
private:
bool gameOver = false;
};
