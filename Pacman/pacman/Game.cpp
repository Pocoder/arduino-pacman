#include "Game.h"

void Game::update(TSPoint p){
  if (p.x>0 && p.x<120 && p.y<240 &&p.y>80){
    curDir = Direction::LEFT;
  }
  if (p.x>120 && p.y<240 &&p.y>80){
    curDir = Direction::RIGHT;
  }
  if (p.y >0 && p.y<80){
    curDir = Direction::TOP;
    Serial.print(p.y);
  }
  if (p.y>240){
    curDir = Direction::DOWN;
  }
  switch (curDir){
    case Direction::LEFT:
      if (pacmanMap[char(curX-0.25)][char(curY)]!=1){
        output.refreshText(8*curX,8*curY,8*(curX-0.25),8*curY);
        curX-=0.25;
      }
      break;
    case Direction::RIGHT:
      if (pacmanMap[char(curX+1)][char(curY)]!=1){
        output.refreshText(8*(curX-0.25),8*curY,8*(curX+=0.25),8*curY);
//        curX+=0.25;
      }
      break;
    case Direction::TOP:
      if (pacmanMap[char(curX)][char(curY-0.25)]!=1){
        output.refreshText(8*curX,8*curY,8*curX,8*(curY-0.25));
        curY-=0.25;
      }
      break;
    case Direction::DOWN:
      if (pacmanMap[char(curX)][char(curY+1)]!=1){
        output.refreshText(8*curX,8*curY,8*curX,8*(curY+0.25));
        curY+=0.25;
      }
      break;
  }
  delay(100);
}


void Game::start(){
  curX =14;
  curY = 27;
  points = 0;
  lives = 3;
  gameOver = false;
  output.loadGame();
}

void Game::startNewLevel(){
  curX = 14;
  curY = 27;
  output.loadGame();
}
