#pragma once
#include "Adafruit_GFX.h"
#include <MCUFRIEND_kbv.h>
#include "MyString.h"

#define BLACK   0xFFFF
#define BLUE    0xFFE0
#define RED     0x07FF
#define GREEN   0xF81F
#define CYAN    0xF800
#define MAGENTA 0x07E0
#define YELLOW  0x001F
#define WHITE   0x0000

enum class Direction {
  LEFT,
  RIGHT,
  TOP,
  DOWN
};

class OutputManager {
public:
  OutputManager(MCUFRIEND_kbv* p);

  void oprint(int x, int y, char* text);
  void rect(int x,int y, int width,int height);
  void load(); //loading screen
  void enterName(MyString& name); //back of entering name
  void writeName(MyString& name); //showing name
  void loadMenu();
  void loadSettings();
  void loadRecords();
  void loadGame();
  void loadStats(int points, int8_t lives, int* energ);
  void loadGameOver();
  void refreshPacman(int oldX,int oldY, int newX,int newY, int8_t curTexture, Direction curDir);
  void refreshGhost(int oldX,int oldY, int newX,int newY, int color, bool eyeMode);
  void refreshPoints(int value);
  void refreshLives(int8_t lives);
private:
  MCUFRIEND_kbv* tft;
};
