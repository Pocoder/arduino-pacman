#include "Game.h"
void Game::refr(){
  curTexture = 3;
  curDir = Direction::RIGHT;
  prevDir = curDir;
  curX = 14.5;
  curY = 27;
}

void Game::moveFunc(Direction dir){
  switch (dir){
    case Direction::LEFT:
      moveOptimisation(-0.125,0,-0.125,0.875,-0.25,0,dir);
      break;
    case Direction::RIGHT:
      moveOptimisation(1,0,1,0.875,0.25,0,dir);
      break;
    case Direction::TOP:
      moveOptimisation(0,-0.125,0.875,-0.125,0,-0.25,dir);  
      break;
    case Direction::DOWN:
      moveOptimisation(0,1.125,0.875,1.125,0,0.25,dir);  
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
  deathCheck();
  
  moveFunc(curDir);
  
  if (trouble){
    moveFunc(prevDir); 
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
  deathCheck();

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
  if (lives <= 0 || gameOver)
    gameOver = true;
  else{
    output.refreshPacman(curX*8,curY*8,14*8+4,27*8, curTexture, curDir);
    refr();
    output.refreshLives(lives);
    EManager.startNewLevel();
    
    countdown();
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
  EManager.startNewLevel();
  output.loadStats(points, lives, ens);
  
  countdown();
}
