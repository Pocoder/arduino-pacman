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

struct Records{
  MyString recNames[6];
  int recResults[6];
  int count = 0;
};

class OutputManager {
public:
  OutputManager(MCUFRIEND_kbv* p);

  void load(); //loading screen
  void enterName(MyString& name); //back of entering name
  void writeName(MyString& name); //showing name
  void loadMenu();
  void loadSettings();
  void loadRecords(Records* recs);
private:
  MCUFRIEND_kbv* tft;
};
