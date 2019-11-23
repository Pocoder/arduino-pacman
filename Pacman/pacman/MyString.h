#pragma once

class MyString {
public:
  MyString();
  MyString(int n);
  MyString(MyString& ms);

  void push(char c);
  void backspace();
  //Потеря владения (плохо), не забыть удалить в другом месте
  char* str();
  char& operator[](int index);
  void copy(const char* mas, int n);

  char* getData();
  int getSize();
  int getCapacity();

  ~MyString();
private:
  char* data;
  int size;
  int capacity;
};
