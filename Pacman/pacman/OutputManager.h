#pragma once
#include "Adafruit_GFX.h"
#include <MCUFRIEND_kbv.h>

#define BLACK   0xFFFF
#define BLUE    0xFFE0
#define RED     0x07FF
#define GREEN   0xF81F
#define CYAN    0xF800
#define MAGENTA 0x07E0
#define YELLOW  0x001F
#define WHITE   0x0000

class OutputManager {
public:
  OutputManager(MCUFRIEND_kbv* p);
  void load();
  void enterName();
private:
  MCUFRIEND_kbv* tft;
};
