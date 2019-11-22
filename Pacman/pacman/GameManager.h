#pragma once
#include <string>
#include <map>
#include "InputManager.h"
#include "OutputManager.h"
#include "Game.h"

class GameManager {
public:
  GameManager();          //конструктор

  void load();            //заставка игры
  void enterName();       //переходит в ввод имени
  void openMenu();        //переходит в меню
  void startGame();       //начинает новую игру
  void openSettengs();    //открывает настройки
  void openRecords();     //открывает топ игроков
  void gameOver();        //заканчиывает игру

  void update();          //считывает нажатие и изменяет состояние игры
private:
  std::map<int, std::string> records;

  enum class State {
    LOADING,
    ENTERING_NAME,
    MENU,
    SETTINGS,
    RECORDS,
    IN_GAME, 
    GAME_OVER
  };

  State curState;
};
