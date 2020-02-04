#pragma once

#define BLACK   0xFFFF
#define PINK 0xF077
#define RED     0x07FF
#define CYAN    0xF800
#degine ORANGE 0xFD00
#define WHITE   0x0000

enum class Direction {
  LEFT,
  RIGHT,
  TOP,
  DOWN
};

struct Point {
  double x;
  double y;
};

class Enemy {
public:
  void calculateDirection();
  void start(uint8_t dots);
  bool isStarted();
  Point getPosition(){
    return position;
  }
private:
  int homePoint;
  int targetPoint;
  int color;
  bool started = false; 
  long long int startDots;
  double speed;
  Point position;
  Direction curDir;
};

//всегда преследует, разбегается в правый верхний угол
class Blinky : public Enemy{
public:
private:
  color = RED;
};

//на 4 клетки вперед пакмана, разбегается в левый верхний угол
class Pinky : public Enemy{
public:
private:
  color = PINK;
};

//выходит через 30 точек, Идет по вектору красного*2, разбегается в правый нижний угол
class Inky : public Enemy{
public:
private:
  color = CYAN;
};

// выходит через 80 точек, идет к пакману как красный, когда дальше чем на 8 клеток,
// иначе домой, разбегается в левый нижний угол
class Clyde : public Enemy{
public:
private:
  color = ORANGE;  
};
