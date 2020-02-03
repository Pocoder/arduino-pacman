#pragma once

enum class Direction {
  LEFT,
  RIGHT,
  TOP,
  DOWN
};

struct Point {
  int x;
  int y;
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
  int color;
  bool started = false; 
  long long int startDots;
  int speed;
  Point position;
  Direction curDir;
};
