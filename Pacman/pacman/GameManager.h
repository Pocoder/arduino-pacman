#pragma once
#include "OutputManager.h"
#include "InputManager.h"
#include "Game.h"

enum class State {
  LOADING,
  ENTERING_NAME,
  MENU,
  SETTINGS,
  RECORDS,
  IN_GAME,
  GAME_OVER
};

class GameManager {
public:
  GameManager(OutputManager& OM, InputManager& IM) :output(OM), input(IM), game(OM) {
    name.copy("Player\0", 6);
  };          //конструктор

  void load();            //заставка игры
  void enterName();       //переходит в ввод имени
  void openMenu();        //переходит в меню
  void startGame();       //начинает новую игру
  void openSettings();    //открывает настройки
  void openRecords();     //открывает топ игроков
  void gameOver();        //заканчиывает игру

  void update();          //считывает нажатие и изменяет состояние игры

private:
  void dealKeyboard(TSPoint p);
  void dealMenuButtons(TSPoint p);
  void dealSettingsButtons(TSPoint p);
  void dealRecordsButtons(TSPoint p);
  void dealGameButtons(TSPoint p);
  void dealGameOverButtons(TSPoint p);

  OutputManager& output;
  InputManager& input;

  Records recs;

  Game game;
  MyString name;
  State curState;
};
