#include "Game.h"

bool isBorder(char x, char y){
  int num = 5*x + y/8;
  int8_t mask = 1<<(7-y%8);
  return bordersMap[num] & mask;
}

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
      if (!isBorder(char(curX-0.25),char(curY)) && !isBorder(char(curX-0.25),char(curY+0.875))){
        output.refreshPacman(8*curX,8*curY,8*(curX-0.25),8*curY);
        curX-=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
    case Direction::RIGHT:
      if (!isBorder(char(curX+1), char(curY))&& !isBorder(char(curX+1), char(curY+0.875))){
        output.refreshPacman(8*curX,8*curY,8*(curX+0.25),8*curY);
        curX+=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
    case Direction::TOP:
      if (!isBorder(char(curX),char(curY-0.25)) && !isBorder(char(curX+0.875),char(curY-0.25))){
        output.refreshPacman(8*curX,8*curY,8*curX,8*(curY-0.25));
        curY-=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
    case Direction::DOWN:
      if (!isBorder(char(curX),char(curY+1.125)) && !isBorder(char(curX+0.875),char(curY+1.125))){
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
        if (!isBorder(char(curX-0.25),char(curY)) && !isBorder(char(curX-0.25),char(curY+0.875))){
          output.refreshPacman(8*curX,8*curY,8*(curX-0.25),8*curY);
          curX-=0.25;
          trouble = false;
        } else
          trouble = true;
        break;
      case Direction::RIGHT:
        if (!isBorder(char(curX+1), char(curY))&& !isBorder(char(curX+1), char(curY+0.875))){
          output.refreshPacman(8*curX,8*curY,8*(curX+0.25),8*curY);
          curX+=0.25;
          trouble = false;
        } else
          trouble = true;
        break;
      case Direction::TOP:
        if (!isBorder(char(curX),char(curY-0.25)) && !isBorder(char(curX+0.875),char(curY-0.25))){
          output.refreshPacman(8*curX,8*curY,8*curX,8*(curY-0.25));
          curY-=0.25;
          trouble = false;
        } else
          trouble = true;
        break;
      case Direction::DOWN:
        if (!isBorder(char(curX),char(curY+1.125)) && !isBorder(char(curX+0.875),char(curY+1.125))){
          output.refreshPacman(8*curX,8*curY,8*curX,8*(curY+0.25));
          curY+=0.25;
          trouble = false;
        } else
          trouble = true;
        break;
    } 
  }else
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
