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

class Unit {
public:
  //конструктор, принимающий начальное положение юнита
  Unit(Point position_,int speed_):speed(speed_),position(position_){}

protected:
  int speed;
  Point position;
  Direction curDir;
};

class Enemy : public Unit {
public:
  void calculateDirection();
private:

};
