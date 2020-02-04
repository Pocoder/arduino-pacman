#include "Units.h"

double calculateDist(double x1, double y1, double x2, double y2){
  return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

bool border(char x, char y){
  if (x<=0 && y==18)
    return false;
  if ((x<=0 || x>=28) && y!=18)
    return true;
  int num = 5*x + y/8;
  int8_t mask = 1<<(7-y%8);
  return bordersMap[num] & mask;
}

void Enemy::calculateDirection();
void Enemy::startNewLevel(OutputManager& output){
  eyeMode = false;
  started = false;
  curDir = Direction::RIGHT;
  output.refreshGhost(int(position.x*8),int(position.y*8), int(startPoint.x*8),int(startPoint.y*8), color, eyeMode);
  position = startPoint;
}

void Blinky::calculateDirection(double curX, double curY, Direction pacmanDir, uint8_t* pointMap) {
  double minDist = 3600000;
  Direction nextDir = curDir;
  if (!border(char(position.x-0.126),char(position.y)) && 
      !border(char(position.x-0.126),char(position.y + 0.875)) && (curDir!=Direction::LEFT)){
    double dist = calculateDist(curX-0.125,curY, position.x, position.y);
    if (dist < minDist){
      nextDir = Direction::LEFT;
      minDist = dist;
    }
  }
  if (!border(char(position.x+1),char(position.y)) && 
      !border(char(position.x+1),char(position.y + 0.875)) && (curDir!=Direction::RIGHT)){
    double dist = calculateDist(curX+1,curY, position.x, position.y);
    if (dist < minDist){
      nextDir = Direction::RIGHT;
      minDist = dist;
    }
  }
  if (!border(char(position.x),char(position.y - 0.125)) && 
      !border(char(position.x+0.875),char(position.y - 0.125)) && (curDir!=Direction::TOP)){
    double dist = calculateDist(curX,curY-0.125, position.x, position.y);
    if (dist < minDist){
      nextDir = Direction::TOP;
      minDist = dist;
    }
  }
  if (!border(char(position.x),char(position.y + 1.125)) && 
      !border(char(position.x+0.875),char(position.y + 1.125)) && (curDir!=Direction::DOWN)){
    double dist = calculateDist(curX,curY+1.125, position.x, position.y);
    if (dist < minDist){
      nextDir = Direction::DOWN;
      minDist = dist;
    }
  }
  curDir = nextDir;
}
