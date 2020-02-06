#pragma once
#include "OutputManager.h"
#include "Textures.cpp"

#define BLACK   0xFFFF
#define PINK    0x07EC //
#define RED     0x07FF
#define CYAN    0xF800
#define ORANGE  0x03BF //
#define WHITE   0x0000

bool isBorder(char x, char y);
bool isPoint(uint8_t x, uint8_t y, uint8_t* curPointsMap);

struct Point {
  double x;
  double y;
};

enum class GhostsState{
  Chase,
  Scatter,
  Frightened
};

class Enemy {
public:
  void move(OutputManager& output, uint8_t* pointMap, int* energ, int dots);
  void calculateDirection(double curX, double curY, Direction pacmanDir, uint8_t* pointMap);
  void startNewLevel(OutputManager& om);
  bool isStarted() { return started; };
  Point getPosition(){ return pos; };
  void setPosition(Point newPos){ pos = newPos; };

  void chase();
  void scatter();
  void frightened();
protected:
  GhostsState state = GhostsState::Scatter;
  bool eyeMode = false;
  Point startPoint;
  Point homePoint;
  Point targetPoint;
  
  int color;
  bool started = false; 
  long long int startDots;
  double speed = 0.25;
  Point pos;
  Direction curDir;
};

//всегда преследует, разбегается в правый верхний угол
class Blinky : public Enemy{
public:
  Blinky(){
    startDots = 0;
    color = RED;
    startPoint = {14.5, 15};
    homePoint = {25, 7};
  };
  //void calculateDirection(double curX, double curY, Direction pacmanDir, uint8_t* pointMap);
private:
};

//на 4 клетки вперед пакмана, разбегается в левый верхний угол
class Pinky : public Enemy{
public:
  Pinky() {
    startDots = 0;
    color = PINK;
    startPoint = {14.5, 18};
    homePoint = {4, 7};
  };
private:
};

//выходит через 30 точек, Идет по вектору красного*2, разбегается в правый нижний угол
class Inky : public Enemy{
public:
  Inky() {
    startDots = 30;
    color = CYAN;
    startPoint = {12.5, 18};
    homePoint = {21, 32};
  };
private:
};

// выходит через 80 точек, идет к пакману как красный, когда дальше чем на 8 клеток,
// иначе домой, разбегается в левый нижний угол
class Clyde : public Enemy{
public:
  Clyde() {
    startDots = 70;
    color = ORANGE;  
    startPoint = {16.5, 18};
    homePoint = {8, 32};
  };
private:
};
