#include "Units.h"

void Enemy::chase(){
  state = GhostsState::Chase;
}
void Enemy::scatter(){
  state = GhostsState::Scatter;
}
void Enemy::frightened(){
  state = GhostsState::Frightened;
}

void Enemy::killed(OutputManager& output){
  dead = true;
  output.refreshGhost(int(pos.x*8),int(pos.y*8),int(startPoint.x*8),int(startPoint.y*8),color,eyeMode);
  pos = startPoint;
}

void Enemy::revive(OutputManager& output){
  if (!dead)
    return;
  else{
    dead = false;
    output.refreshGhost(int(pos.x*8),int(pos.y*8),int(14.5*8),int(15*8),color,eyeMode);
    pos.x = 14.5;
    pos.y = 15;
  }
}

bool isBorder(char x, char y){
  if (x<=0 && y==18)
    return false;
  if ((x<=0 || x>=28) && y!=18)
    return true;
  int num = 5*x + y/8;
  int8_t mask = 1<<(7-y%8);
  return bordersMap[num] & mask;
}
bool isPoint(uint8_t x, uint8_t y, uint8_t* curPointsMap){
  uint8_t num = 5*x + y/8;
  uint8_t mask = 1<<(7-y%8);
  return curPointsMap[num] & mask;
}

double calculateDist(double x1, double y1, double x2, double y2){
  return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

void Enemy::startNewLevel(OutputManager& output){
  dead = false;
  inCage = true;
  eyeMode = false;
  curDir = Direction::NONE;
  output.refreshGhost(int(pos.x*8),int(pos.y*8), int(startPoint.x*8),int(startPoint.y*8), color, eyeMode);
  pos = startPoint;
}

void Enemy::calculateDirection(double curX, double curY, Direction pacmanDir, uint8_t* pointMap) {
  if (state == GhostsState::Scatter){
    curX = homePoint.x;
    curY = homePoint.y;
  }
  if (state == GhostsState::Frightened){
    curX = random(30);
    curY = random(40);
  }
  double minDist = 3600000;
  Direction nextDir = curDir;
  if (!isBorder(char(pos.x-0.126),char(pos.y)) && 
      !isBorder(char(pos.x-0.126),char(pos.y + 0.875)) && (curDir!=Direction::RIGHT)){
    double dist = calculateDist(curX,curY, pos.x-1, pos.y);
    if (dist < minDist){
      nextDir = Direction::LEFT;
      minDist = dist;
    }
  }
  if (!isBorder(char(pos.x+1),char(pos.y)) && 
      !isBorder(char(pos.x+1),char(pos.y + 0.875)) && (curDir!=Direction::LEFT)){
    double dist = calculateDist(curX,curY, pos.x+1, pos.y);
    if (dist < minDist){
      nextDir = Direction::RIGHT;
      minDist = dist;
    }
  }
  if (!isBorder(char(pos.x),char(pos.y - 0.125)) && 
      !isBorder(char(pos.x+0.875),char(pos.y - 0.125)) && (curDir!=Direction::DOWN)){
    double dist = calculateDist(curX,curY, pos.x, pos.y-1);
    if (dist < minDist){
      nextDir = Direction::TOP;
      minDist = dist;
    }
  }
  if (!isBorder(char(pos.x),char(pos.y + 1.125)) && 
      !isBorder(char(pos.x+0.875),char(pos.y + 1.125)) && (curDir!=Direction::TOP)){
    double dist = calculateDist(curX,curY, pos.x, pos.y+1);
    if (dist < minDist){
      nextDir = Direction::DOWN;
      minDist = dist;
    }
  }
  curDir = nextDir;
}

void Enemy::move(OutputManager& output, uint8_t* pointMap, int dots){
  if (dead)
    return;
  if (244 - dots < startDots)
    return;
  int col = color;
  if (state == GhostsState::Frightened)
    col = BLUE;
  if (inCage){
    inCage = false;
    output.refreshGhost(int(pos.x*8),int(pos.y*8),int(14.5*8),int(15*8),col,eyeMode);
    pos.x = 14.5;
    pos.y = 15;
  }
  if (pos.x > 30.25)
    pos.x -= 30;
  if (pos.x < -1.25)
    pos.x += 30;

  switch (curDir){
    case Direction::LEFT:
      output.refreshGhost(int((pos.x+speed)*8),int(pos.y*8),int((pos.x-=speed)*8),int(pos.y*8),col,eyeMode);
      break;
    case Direction::RIGHT:
      output.refreshGhost(int((pos.x-speed)*8),int(pos.y*8),int((pos.x+=speed)*8),int(pos.y*8),col,eyeMode);
      break;
    case Direction::TOP:
      output.refreshGhost(int(pos.x*8),int((pos.y+speed)*8),int(pos.x*8),int((pos.y-=speed)*8),col,eyeMode);
      break;
    case Direction::DOWN:
      output.refreshGhost(int(pos.x*8),int((pos.y-speed)*8),int(pos.x*8),int((pos.y+=speed)*8),col,eyeMode);
      break;
  }

  uint8_t pointX = uint8_t(pos.x);
  uint8_t pointY = uint8_t(pos.y);
  
  if (isPoint(pointX-1,pointY,pointMap))
    output.refreshDot(pointX-1,pointY);
  if (isPoint(pointX+1,pointY,pointMap))
    output.refreshDot(pointX+1,pointY);
  if (isPoint(pointX,pointY-1,pointMap))
    output.refreshDot(pointX,pointY-1);
  if (isPoint(pointX,pointY+1,pointMap))
    output.refreshDot(pointX,pointY+1);
}
