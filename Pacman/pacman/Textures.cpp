#include <avr/pgmspace.h>

const uint8_t pacman1R[]PROGMEM = {
 0x00,0x00,
 0x03,0xC0,
 0x0f,0xf0,//
 0x1f,0xe0,
 0x3f,0xc0,
 0x3f,0xc0,
 0x7f,0x80,
 0x7f,0x00, //8
 0x7f,0x00,
 0x7f,0x80,
 0x3f,0xc0,
 0x3f,0xc0,
 0x1f,0xe0,
 0x0f,0xf0,//
 0x03,0xC0,
 0x00,0x00,
};

const uint8_t pacman2R[]PROGMEM = {
 0x00,0x00,
 0x03,0xC0,
 0x0f,0xf0,//
 0x1f,0xf8,
 0x3f,0xf8,
 0x3f,0xf0,
 0x7f,0xc0,
 0x7f,0x00, //8
 0x7f,0x00,
 0x7f,0xc0,
 0x3f,0xf0,
 0x3f,0xf8,
 0x1f,0xf8,
 0x0f,0xf0,//
 0x03,0xC0,
 0x00,0x00,
};

const uint8_t pacman1L[]PROGMEM = {
 0x00,0x00,
 0x03,0xC0,
 0x0f,0xf0,//
 0x07,0xf8,
 0x03,0xfc,
 0x03,0xfc,
 0x01,0xfe,
 0x00,0xfe, //8
 0x00,0xfe, //8
 0x01,0xfe,
 0x03,0xfc,
 0x03,0xfc,
 0x07,0xf8,
 0x0f,0xf0,//
 0x03,0xC0,
 0x00,0x00,
};

const uint8_t pacman2L[]PROGMEM = {
 0x00,0x00,
 0x03,0xC0,
 0x0f,0xf0,//
 0x1f,0xf8,
 0x1f,0xfc,
 0x0f,0xfc,
 0x03,0xfe,
 0x00,0xfe, //8
 0x00,0xfe, //8
 0x03,0xfe,
 0x0f,0xfc,
 0x1f,0xfc,
 0x1f,0xf8,
 0x0f,0xf0,//
 0x03,0xC0,
 0x00,0x00,
};

const uint8_t pacman1T[]PROGMEM = {
 0x00,0x00,
 0x00,0x00,
 0x00,0x00,
 0x00,0x00,
 0x20,0x04,
 0x30,0x0c,
 0x7c,0x3e,
 0x3e,0x7e, //8
 0x7f,0xfe, 
 0x7f,0xfe,
 0x3f,0xfc,
 0x3f,0xfc,
 0x1f,0xf8,
 0x0f,0xf0,
 0x03,0xC0,
 0x00,0x00,
};

const uint8_t pacman2T[]PROGMEM = {
 0x00,0x00, //1
 0x00,0x00, //2
 0x00,0x00, //3
 0x18,0x18, //4
 0x3c,0x3c, //5
 0x3c,0x3c, //6
 0x7e,0x7e, //7
 0x7e,0x7e, //8
 0x7f,0xfe, //9
 0x7f,0xfe, //10
 0x3f,0xfc, //11
 0x3f,0xfc, //12
 0x1f,0xf8, //13
 0x0f,0xf0, //14
 0x03,0xC0, //15
 0x00,0x00, //16
};

const uint8_t pacman1D[]PROGMEM = {
 0x00,0x00, //16
 0x03,0xC0, //15
 0x0f,0xf0, //14
 0x1f,0xf8, //13
 0x3f,0xfc, //12
 0x3f,0xfc, //11
 0x7f,0xfe, //10
 0x7f,0xfe, //9
 0x3e,0x7e, //8
 0x7c,0x3e, //7
 0x30,0x0c, //6
 0x20,0x04, //5
 0x00,0x00, //4
 0x00,0x00, //3
 0x00,0x00, //2
 0x00,0x00, //1
};

const uint8_t pacman2D[]PROGMEM = {
 0x00,0x00, //16
 0x03,0xC0, //15
 0x0f,0xf0, //14
 0x1f,0xf8, //13
 0x3f,0xfc, //12
 0x3f,0xfc, //11
 0x7f,0xfe, //10
 0x7f,0xfe, //9
 0x7e,0x7e, //8
 0x7e,0x7e, //7
 0x3c,0x3c, //6
 0x3c,0x3c, //5
 0x18,0x18, //4
 0x00,0x00, //3
 0x00,0x00, //2
 0x00,0x00, //1
};

const uint8_t pacman3[]PROGMEM = {
 0x00,0x00,
 0x03,0xC0,
 0x0f,0xf0,
 0x1f,0xf8,
 0x3f,0xfc,
 0x3f,0xfc,
 0x7f,0xfe,
 0x7f,0xfe, //8
 0x7f,0xfe,
 0x7f,0xfe,
 0x3f,0xfc,
 0x3f,0xfc,
 0x1f,0xf8,
 0x0f,0xf0,
 0x03,0xC0,
 0x00,0x00,
};

const uint8_t bordersMap[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0F, 0xFE, 0xDB, 0xFF, 0xE0, 
  0x08, 0x06, 0xDB, 0x0C, 0x20,
  0x0B, 0xB6, 0xDB, 0x6D, 0xA0, 
  0x0B, 0xB6, 0xDB, 0x61, 0xA0, 
  0x0B, 0xB6, 0xDB, 0x7D, 0xA0, 
  0x0B, 0xB7, 0xDF, 0x7D, 0xA0, 
  0x08, 0x00, 0x00, 0x01, 0xA0, 
  0x0B, 0xBF, 0xDF, 0x6F, 0xA0, 
  0x0B, 0xBF, 0xDF, 0x6F, 0xA0, 
  0x0B, 0x86, 0x00, 0x61, 0xA0, 
  0x0B, 0xB6, 0xFB, 0x6D, 0xA0, 
  0x0B, 0xB6, 0x8B, 0x6D, 0xA0, 
  0x08, 0x30, 0x8B, 0x0C, 0x20, 
  0x0F, 0xBE, 0x8B, 0xEF, 0xA0, 
  0x0F, 0xBE, 0x8B, 0xEF, 0xA0, 
  0x08, 0x30, 0x8B, 0x0C, 0x20, 
  0x0B, 0xB6, 0x8B, 0x6D, 0xA0, 
  0x0B, 0xB6, 0xFB, 0x6D, 0xA0, 
  0x0B, 0x86, 0x00, 0x61, 0xA0, 
  0x0B, 0xBF, 0xDF, 0x6F, 0xA0, 
  0x0B, 0xBF, 0xDF, 0x6F, 0xA0, 
  0x08, 0x00, 0x00, 0x01, 0xA0, 
  0x0B, 0xB7, 0xDF, 0x7D, 0xA0, 
  0x0B, 0xB6, 0xDB, 0x7D, 0xA0, 
  0x0B, 0xB6, 0xDB, 0x61, 0xA0, 
  0x0B, 0xB6, 0xDB, 0x6D, 0xA0, 
  0x08, 0x06, 0xDB, 0x0C, 0x20, 
  0x0F, 0xFE, 0xDB, 0xFF, 0xE0, 
  0x00, 0x00, 0x00, 0x00, 0x00, 
};  

const uint8_t pointsMap[] = {
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x06, 0xF8, 0x00, 0xE3, 0xC0,
  0x04, 0x48, 0x00, 0x92, 0x40,
  0x04, 0x48, 0x00, 0x9E, 0x40,
  0x04, 0x48, 0x00, 0x82, 0x40,
  0x04, 0x48, 0x00, 0x82, 0x40,
  0x07, 0xFF, 0xFF, 0xFE, 0x40,
  0x04, 0x40, 0x00, 0x90, 0x40,
  0x04, 0x40, 0x00, 0x90, 0x40,
  0x04, 0x78, 0x00, 0x9E, 0x40,
  0x04, 0x48, 0x00, 0x92, 0x40,
  0x04, 0x48, 0x00, 0x92, 0x40,
  0x07, 0xC8, 0x00, 0xF3, 0xC0,
  0x00, 0x40, 0x00, 0x00, 0x40,
  0x00, 0x40, 0x00, 0x00, 0x40,
  0x07, 0xC8, 0x00, 0xF3, 0xC0,
  0x04, 0x48, 0x00, 0x92, 0x40,
  0x04, 0x48, 0x00, 0x92, 0x40,
  0x04, 0x78, 0x00, 0x9E, 0x40,
  0x04, 0x40, 0x00, 0x90, 0x40,
  0x04, 0x40, 0x00, 0x90, 0x40,
  0x07, 0xFF, 0xFF, 0xFE, 0x40,
  0x04, 0x48, 0x00, 0x82, 0x40,
  0x04, 0x48, 0x00, 0x82, 0x40,
  0x04, 0x48, 0x00, 0x9E, 0x40,
  0x04, 0x48, 0x00, 0x92, 0x40,
  0x06, 0xF8, 0x00, 0xE3, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 
};

/*const uint8_t pacmanMap[30][40] = {                         //ent
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//0 +
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},//1 +
    {0,0,0,0,1,2,2,3,2,2,2,2,2,1,1,0,1,1,0,1,1,0,1,1,2,2,2,3,1,1,2,2,2,2,1,0,0,0,0,0},//2 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,1,1,0,1,1,0,1,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0,0},//3 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,1,1,0,1,1,0,1,1,2,1,1,2,2,2,2,1,1,2,1,0,0,0,0,0},//4 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,1,1,0,1,1,0,1,1,2,1,1,1,1,1,2,1,1,2,1,0,0,0,0,0},//5 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,1,1,1,0,1,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,0,0,0,0,0},//6 +
    {0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,1,0,0,0,0,0},//7 +
    {0,0,0,0,1,2,1,1,1,2,1,1,1,1,1,1,1,1,0,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,0,0,0,0,0},//8 +
    {0,0,0,0,1,2,1,1,1,2,1,1,1,1,1,1,1,1,0,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,0,0,0,0,0},//9 +
    {0,0,0,0,1,2,1,1,1,2,2,2,2,1,1,0,0,0,0,0,0,0,0,0,2,1,1,2,2,2,2,1,1,2,1,0,0,0,0,0},//10 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,1,1,1,1,1,0,1,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0,0},//11 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,1,0,0,0,1,0,1,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0,0},//12 +
    {0,0,0,0,1,2,2,2,2,2,1,1,2,0,0,0,1,0,0,0,1,0,1,1,2,2,2,2,1,1,2,2,2,2,1,0,0,0,0,0},//13 +
    {0,0,0,0,1,1,1,1,1,2,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,2,1,0,0,0,0,0},//14 +
    {0,0,0,0,1,1,1,1,1,2,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,2,1,0,0,0,0,0 },//14 +
    {0,0,0,0,1,2,2,2,2,2,1,1,2,0,0,0,1,0,0,0,1,0,1,1,2,2,2,2,1,1,2,2,2,2,1,0,0,0,0,0 },//13 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,1,0,0,0,1,0,1,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0,0 },//12 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,1,1,1,1,1,0,1,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0,0 },//11 +
    {0,0,0,0,1,2,1,1,1,2,2,2,2,1,1,0,0,0,0,0,0,0,0,0,2,1,1,2,2,2,2,1,1,2,1,0,0,0,0,0 },//10 +
    {0,0,0,0,1,2,1,1,1,2,1,1,1,1,1,1,1,1,0,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,0,0,0,0,0 },//9 +
    {0,0,0,0,1,2,1,1,1,2,1,1,1,1,1,1,1,1,0,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,0,0,0,0,0 },//8 +
    {0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,1,0,0,0,0,0 },//7 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,1,1,1,0,1,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,0,0,0,0,0 },//6 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,1,1,0,1,1,0,1,1,2,1,1,1,1,1,2,1,1,2,1,0,0,0,0,0 },//5 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,1,1,0,1,1,0,1,1,2,1,1,2,2,2,2,1,1,2,1,0,0,0,0,0 },//4 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,1,1,0,1,1,0,1,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0,0 },//3 +
    {0,0,0,0,1,2,2,3,2,2,2,2,2,1,1,0,1,1,0,1,1,0,1,1,2,2,2,3,1,1,2,2,2,2,1,0,0,0,0,0 },//2 +
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},//1 +
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//0 +
  }; */
