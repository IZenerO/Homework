#include <iostream>
#include "Homework8_task2_singleton.hpp"

Singleton& Singleton::getInstance() {
  static Singleton instance;
  return instance;
}

int Singleton::add(int value) {
  if (position == ARRAY_SIZE) {
    std::cout << "Array is full\n";
    return 0;
  }
  array[position++] = value;
  return array[position];
}

void Singleton::show () const {
  for (uint32_t i = 0; i < ARRAY_SIZE; ++i) {
    std::cout << array[i] << " ";
  }
}