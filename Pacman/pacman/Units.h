#pragma once

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
