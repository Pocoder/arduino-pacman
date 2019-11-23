#include "MyString.h"

MyString::MyString() {
  size = 0;
  capacity = 6;
  data = new char[7];
};
MyString::MyString(int n) {
  data = new char[n + 1];
  size = 0;
  capacity = n;
};
MyString::MyString(MyString& ms) {
  data = ms.getData();
  capacity = ms.getCapacity();
  size = ms.getSize();
};

void MyString::push(char c) {
  if (size < capacity) {
    data[size] = c;
  }
  else {
    char* temp = data;
    data = new char[capacity * 2 + 1];
    for (int i = 0; i < capacity; i++) {
      data[i] = temp[i];
    }
    delete[] temp;
    data[capacity] = c;
    capacity *= 2;
  }
  size++;
}
void MyString::backspace() {
  size--;
}
//Потеря владения (плохо), не забыть удалить в другом месте
char* MyString::str() {
  char* result = new char[size + 1];
  for (int i = 0; i < size; i++) {
    result[i] = data[i];
  }
  result[size] = '\0';
  return result;
}
char& MyString::operator[](int index) {
  return data[index];
}

void MyString::copy(const char* mas, int n) {
  delete[] data;
  size = n;
  capacity = n;
  data = new char[n + 1];
  for (int i = 0; i < n; i++) {
    data[i] = mas[i];
  }
  data[n] = '\0';
}

char* MyString::getData() {
  return data;
}
int MyString::getSize() {
  return size;
}
int MyString::getCapacity() {
  return capacity;
}

MyString::~MyString() {
  delete[] data;
}
