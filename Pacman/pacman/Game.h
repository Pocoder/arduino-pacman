#pragma once
#include <string>
#include "Units.h"

class Game {
public:
  Game(std::string name); //конструктор
  void loadLevel();
private:
  //units
  Hero pacman;
  Blinky blinky;
  Pinky pinky;
  Inky inky;
  Clyde clyde;

  //state
  int curLevel = 1;
  int points = 0;
  std::string playerName = "player";

  //map
  static const int cols = 40;
  static const int rows = 30;
  const unsigned char pacmanMap[rows][cols];
};
