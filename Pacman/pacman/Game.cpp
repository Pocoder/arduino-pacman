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
  }
  if (p.y>240){
    curDir = Direction::DOWN;
  }
  //teleport
  if (curX > 30.25)
    curX -= 30;
  if (curX < -1.25)
    curX += 30;
  
  switch (curDir){
    case Direction::LEFT:
      if (pacmanMap[char(curX-0.25)][char(curY)]!=1 && pacmanMap[char(curX-0.25)][char(curY+0.875)]!=1){
        output.refreshPacman(8*curX,8*curY,8*(curX-0.25),8*curY);
        curX-=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
    case Direction::RIGHT:
      if (pacmanMap[char(curX+1)][char(curY)]!=1 && pacmanMap[char(curX+1)][char(curY+0.875)]!=1){
        output.refreshPacman(8*curX,8*curY,8*(curX+0.25),8*curY);
        curX+=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
    case Direction::TOP:
      if (pacmanMap[char(curX)][char(curY-0.25)]!=1 && pacmanMap[char(curX+0.875)][char(curY-0.25)]!=1){
        output.refreshPacman(8*curX,8*curY,8*curX,8*(curY-0.25));
        curY-=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
    case Direction::DOWN:
      if (pacmanMap[char(curX)][char(curY+1.125)]!=1 && pacmanMap[char(curX+0.875)][char(curY+1.125)]!=1){
        output.refreshPacman(8*curX,8*curY,8*curX,8*(curY+0.25));
        curY+=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
  }
  
  if (trouble){
    switch (prevDir){
    case Direction::LEFT:
      if (pacmanMap[char(curX-0.25)][char(curY)]!=1 && pacmanMap[char(curX-0.25)][char(curY+0.875)]!=1){
        output.refreshPacman(8*curX,8*curY,8*(curX-0.25),8*curY);
        curX-=0.25;
      }
      break;
    case Direction::RIGHT:
      if (pacmanMap[char(curX+1)][char(curY)]!=1 && pacmanMap[char(curX+1)][char(curY+0.875)]!=1){
        output.refreshPacman(8*curX,8*curY,8*(curX+0.25),8*curY);
        curX+=0.25;
      } 
      break;
    case Direction::TOP:
      if (pacmanMap[char(curX)][char(curY-0.25)]!=1 && pacmanMap[char(curX+0.875)][char(curY-0.25)]!=1){
        output.refreshPacman(8*curX,8*curY,8*curX,8*(curY-0.25));
        curY-=0.25;
      } 
      break;
    case Direction::DOWN:
      if (pacmanMap[char(curX)][char(curY+1.125)]!=1 && pacmanMap[char(curX+0.875)][char(curY+1.125)]!=1){
        output.refreshPacman(8*curX,8*curY,8*curX,8*(curY+0.25));
        curY+=0.25;
      }
      break;
    } 
  } else
    prevDir = curDir;
  delay(30); //speed
}


void Game::start(){
  curX = 14;
  curY = 27;
  points = 0;
  lives = 3;
  output.loadGame();
  gameOver = false;
}

void Game::startNewLevel(){
  curX = 14;
  curY = 27;
  output.loadGame();
}
