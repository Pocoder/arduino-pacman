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
  Unit(Point position_,int speed_);

  void Move();
protected:
  int speed;
  Point position;
  Direction curDir;
};

class Hero : public Unit {
public:

private:

};

class Enemy : public Unit {
public:
  void calculateDirection();
private:

};

//красный призрак Shadow
class Blinky : public Enemy {
public:

private:

};

//Розовый призрак Speedy
class Pinky : public Enemy {
public:

private:

};

//Голубой призрак Bashful
class Inky : public Enemy {
public:

private:

};

//Оранжевый призрак Pockey
class Clyde : public Enemy {
public:

private:

};
