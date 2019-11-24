#pragma once
/*const unsigned char pacmanMap[30][40] = {                         //ent
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//0 +
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},//1 +
    {0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,0,1,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0},//2 +
    {0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0},//3 +
    {0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,0,0,0,1,1,0,1,0,0,0,0,0},//4 +
    {0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0},//5 +
    {0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0},//6 +
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0},//7 +
    {0,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0},//8 +
    {0,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0},//9 +
    {0,0,0,0,1,0,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,1,0,0,0,0,0},//10 +
    {0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,3,3,3,3,3,0,1,1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0},//11 +
    {0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,3,0,0,0,3,0,1,1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0},//12 +
    {0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,3,0,0,0,3,0,1,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0},//13 +
    {0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,3,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0},//14 +
    {0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,3,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0},//14 +
    {0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,3,0,0,0,3,0,1,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0},//13 +
    {0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,3,0,0,0,3,0,1,1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0},//12 +
    {0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,3,3,3,3,3,0,1,1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0},//11 +
    {0,0,0,0,1,0,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,1,0,0,0,0,0},//10 +
    {0,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0},//9 +
    {0,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0},//8 +
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0},//7 +
    {0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0},//6 +
    {0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0},//5 +
    {0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,0,0,0,1,1,0,1,0,0,0,0,0},//4 +
    {0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0},//3 +
    {0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,0,1,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0},//2 +
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},//1 +
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//0 +
  };*/
const unsigned char pacmanMap[30][40] = {                         //ent
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
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,4,4,4,4,4,0,1,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0,0},//11 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,4,0,0,0,4,0,1,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0,0},//12 +
    {0,0,0,0,1,2,2,2,2,2,1,1,2,0,0,0,4,0,0,0,4,0,1,1,2,2,2,2,1,1,2,2,2,2,1,0,0,0,0,0},//13 +
    {0,0,0,0,1,1,1,1,1,2,1,1,1,1,1,0,4,0,0,0,4,0,1,1,1,1,1,0,1,1,1,1,1,2,1,0,0,0,0,0},//14 +
    {0,0,0,0,1,1,1,1,1,2,1,1,1,1,1,0,4,0,0,0,4,0,1,1,1,1,1,0,1,1,1,1,1,2,1,0,0,0,0,0 },//14 +
    {0,0,0,0,1,2,2,2,2,2,1,1,2,0,0,0,4,0,0,0,4,0,1,1,2,2,2,2,1,1,2,2,2,2,1,0,0,0,0,0 },//13 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,4,0,0,0,4,0,1,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0,0 },//12 +
    {0,0,0,0,1,2,1,1,1,2,1,1,2,1,1,0,4,4,4,4,4,0,1,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0,0 },//11 +
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
  };