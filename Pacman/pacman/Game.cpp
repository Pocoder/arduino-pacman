#include "Game.h"

bool isBorder(char x, char y){
  if (x<=0 && y==18)
    return false;
  if ((x<=0 || x>=28) && y!=18)
    return true;
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

  //GHOSTS
  EManager.update(curX, curY, curDir, curPointsMap, dots);
  
  switch (curDir){
    case Direction::LEFT:
      if (!isBorder(char(curX-0.125),char(curY)) && !isBorder(char(curX-0.125),char(curY+0.875))){
        output.refreshPacman(8*curX,8*curY,8*(curX-0.25),8*curY, curTexture, curDir);
        curX-=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
    case Direction::RIGHT:
      if (!isBorder(char(curX+1), char(curY))&& !isBorder(char(curX+1), char(curY+0.875))){
        output.refreshPacman(8*curX,8*curY,8*(curX+0.25),8*curY, curTexture, curDir);
        curX+=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
    case Direction::TOP:
      if (!isBorder(char(curX),char(curY-0.125)) && !isBorder(char(curX+0.875),char(curY-0.125))){
        output.refreshPacman(8*curX,8*curY,8*curX,8*(curY-0.25), curTexture, curDir);
        curY-=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
    case Direction::DOWN:
      if (!isBorder(char(curX),char(curY+1.125)) && !isBorder(char(curX+0.875),char(curY+1.125))){
        output.refreshPacman(8*curX,8*curY,8*curX,8*(curY+0.25), curTexture, curDir);
        curY+=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
  }
  
  if (trouble){
    switch (prevDir){
      case Direction::LEFT:
        if (!isBorder(char(curX-0.125),char(curY)) && !isBorder(char(curX-0.125),char(curY+0.875))){
          output.refreshPacman(8*curX,8*curY,8*(curX-0.25),8*curY, curTexture, prevDir);
          curX-=0.25;
          trouble = false;
        } else
          trouble = true;
        break;
      case Direction::RIGHT:
        if (!isBorder(char(curX+1), char(curY))&& !isBorder(char(curX+1), char(curY+0.875))){
          output.refreshPacman(8*curX,8*curY,8*(curX+0.25),8*curY, curTexture, prevDir);
          curX+=0.25;
          trouble = false;
        } else
          trouble = true;
        break;
      case Direction::TOP:
        if (!isBorder(char(curX),char(curY-0.125)) && !isBorder(char(curX+0.875),char(curY-0.125))){
          output.refreshPacman(8*curX,8*curY,8*curX,8*(curY-0.25), curTexture, prevDir);
          curY-=0.25;
          trouble = false;
        } else
          trouble = true;
        break;
      case Direction::DOWN:
        if (!isBorder(char(curX),char(curY+1.125)) && !isBorder(char(curX+0.875),char(curY+1.125))){
          output.refreshPacman(8*curX,8*curY,8*curX,8*(curY+0.25), curTexture, prevDir);
          curY+=0.25;
          trouble = false;
        } else
          trouble = true;
        break;
    } 
  }else
    prevDir = curDir;

  //SUPERPOINTS
  if (uint8_t(curX) == 2 && uint8_t(curY) == 7 && BPoint1){
    BPoint1 = false;
    dots--;
    points+= 50;
    output.refreshPoints(points); 
  }
  if (uint8_t(curX) == 27 && uint8_t(curY) == 7 && BPoint2){
    BPoint2 = false;
    dots--;
    points+= 50;
    output.refreshPoints(points); 
  }
  if (uint8_t(curX) == 2 && uint8_t(curY) == 27 && BPoint3){
    BPoint3 = false;
    dots--;
    points+= 50;
    output.refreshPoints(points); 
  }
  if (uint8_t(curX) == 27 && uint8_t(curY) == 27 && BPoint4){
    BPoint4 = false;
    dots--;
    points+= 50;
    output.refreshPoints(points); 
  }
  //POINTS
  if (isPoint(uint8_t(curX),uint8_t(curY))){
    curPointsMap[5*uint8_t(curX) + uint8_t(curY)/8] &= ~(1<<(7-uint8_t(curY)%8));
    dots--;
    points+=10;
    output.refreshPoints(points);
  }

  if (dots == 0){
    output.refreshPacman(curX*8,curY*8,14*8+4,27*8, curTexture, curDir);
    startNewLevel();
  }
  
  ++curTexture %= 4;
  delay(30); //fps
}

void Game::start(){
  output.loadGame();
  points = 0;
  lives = 3;
  startNewLevel();
  gameOver = false;
}

void Game::death(){
  lives--;
  if (lives == 0)
    gameOver = true;
  else{
    curTexture = 0;
    output.refreshPacman(curX*8,curY*8,14*8+4,27*8, curTexture, curDir);
    curDir = Direction::RIGHT;
    curX = 14.5;
    curY = 27;
    output.loadStats(points, lives);
    EManager.startNewLevel();
    
    output.oprint(117,167, "3");
    delay(1000);
    output.rect(80,163,80,10);
    output.oprint(117,167, "2");
    delay(1000);
    output.rect(80,163,80,10);
    output.oprint(117,167, "1");
    delay(1000);
    output.rect(80,163,80,10);
    output.oprint(114,167, "GO");
    delay(100);
    output.rect(80,163,80,14);
  }
}

void Game::startNewLevel(){
  curTexture = 3;
  curDir = Direction::RIGHT;
  BPoint1 = true;
  BPoint2 = true;
  BPoint3 = true;
  BPoint4 = true;
  for (int i = 0;i<150;i++){
    curPointsMap[i] = pointsMap[i];
  }
  dots = 244;
  curX = 14.5;
  curY = 27;
  output.loadStats(points, lives);
  EManager.startNewLevel();
  
  output.oprint(117,167, "3");
  delay(1000);
  output.rect(80,163,80,10);
  output.oprint(117,167, "2");
  delay(1000);
  output.rect(80,163,80,10);
  output.oprint(117,167, "1");
  delay(1000);
  output.rect(80,163,80,10);
  output.oprint(114,167, "GO");
  delay(100);
  output.rect(80,163,80,14);
}
