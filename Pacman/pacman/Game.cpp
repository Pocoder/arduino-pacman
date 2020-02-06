#include "Game.h"
void Game::refr(){
  curTexture = 3;
  curDir = Direction::RIGHT;
  prevDir = curDir;
  curX = 14.5;
  curY = 27;
}

void Game::moveFunc(Direction dir, double& curX, double& curY){
  switch (dir){
    case Direction::LEFT:
      if (!isBorder(char(curX-0.125),char(curY)) && !isBorder(char(curX-0.125),char(curY+0.875))){
        output.refreshPacman(8*curX,8*curY,8*(curX-0.25),8*curY, curTexture, dir);
        curX-=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
    case Direction::RIGHT:
      if (!isBorder(char(curX+1), char(curY))&& !isBorder(char(curX+1), char(curY+0.875))){
        output.refreshPacman(8*curX,8*curY,8*(curX+0.25),8*curY, curTexture, dir);
        curX+= 0.25;
        trouble = false;
      } else
        trouble = true;
      break;
    case Direction::TOP:
      if (!isBorder(char(curX),char(curY-0.125)) && !isBorder(char(curX+0.875),char(curY-0.125))){
        output.refreshPacman(8*curX,8*curY,8*curX,8*(curY-0.25), curTexture, dir);
        curY-=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
    case Direction::DOWN:
      if (!isBorder(char(curX),char(curY+1.125)) && !isBorder(char(curX+0.875),char(curY+1.125))){
        output.refreshPacman(8*curX,8*curY,8*curX,8*(curY+0.25), curTexture, dir);
        curY+=0.25;
        trouble = false;
      } else
        trouble = true;
      break;
  }
}

void Game::update(TSPoint p){
  if (p.y >0 && p.y<80){
    curDir = Direction::TOP;
  }else if (p.y>240){
    curDir = Direction::DOWN;
  }else if (p.x<120 && p.x>0){
    curDir = Direction::LEFT;
  }else if (p.x>120){
    curDir = Direction::RIGHT;
  }
  
  //teleport
  if (curX > 30.25)
    curX -= 30;
  if (curX < -1.25)
    curX += 30;

  //death?
  //if (int(EManager.getBlinkyPos().x+0.5) == int(curX+0.5) && int(EManager.getBlinkyPos().y+0.5) == int(curY+0.5))
  //  death();
  
  moveFunc(curDir, curX, curY);
  
  if (trouble){
    moveFunc(prevDir, curX, curY); 
  }else
    prevDir = curDir;

  //SUPERPOINTS
  for (int i = 0;i<4;i++){
    if ((uint8_t(curX) == (ens[i]>>8)) && (uint8_t(curY) == ((ens[i]<<8)>>8))){
      ens[i] = 0;
      dots--;
      points += 50;
      EManager.startFrightened();
      output.refreshPoints(points); 
    }
  }
  
  //POINTS
  if (isPoint(uint8_t(curX),uint8_t(curY), curPointsMap)){
    curPointsMap[5*uint8_t(curX) + uint8_t(curY)/8] &= ~(1<<(7-uint8_t(curY)%8));
    dots--;
    points+=10;
    output.refreshPoints(points);
  }

  if (dots == 0){
    output.refreshPacman(curX*8,curY*8,14*8+4,27*8, curTexture, curDir);
    startNewLevel();
  }

  //death?
  //if (int(EManager.getBlinkyPos().x+0.5) == int(curX+0.5) && int(EManager.getBlinkyPos().y+0.5) == int(curY+0.5))
  //  death();

  //GHOSTS
  EManager.update(curX, curY, curDir, curPointsMap, dots, ens);
  
  ++curTexture %= 4;
  delay(10); //fps
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
  if (lives <= 0)
    gameOver = true;
  else{
    output.refreshPacman(curX*8,curY*8,14*8+4,27*8, curTexture, curDir);
    refr();
    output.refreshLives(lives);
    EManager.startNewLevel();
    
    account();
  }
}

void Game::startNewLevel(){
  refr();
  for (int i = 0;i<4;i++)
    ens[i] = ensStart[i];
  
  for (int i = 0;i<150;i++){
    curPointsMap[i] = pointsMap[i];
  }
  dots = 244;
  output.loadStats(points, lives, ens);
  EManager.startNewLevel();
  
  account();
}
