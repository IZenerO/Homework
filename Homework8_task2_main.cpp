#include <iostream>
#include "Homework8_task2_singleton.hpp"


int main () {
  Singleton& singl1 = Singleton::getInstance();
  std::cout << "Classic address of singleton object: " << &singl1 << std::endl;
  std::cout << "How much elements you want to enter? ";
  uint32_t num;
  std::cin >> num;
  while (num != 0) {
    int value;
    std::cin >> value;
    singl1.add(value);
    --num;
  }
  singl1.show();

}