#include <iostream>
#include "Homework8_task1_array.hpp"

int main () {
  Array ar;
  std::cout << "How much elements you want to enter? ";
  uint32_t num;
  std::cin >> num;
  while (num != 0) {
    int value;
    std::cin >> value;
    ar.add(value);
    --num;
  }
  std::cout << "Which elements you want to swap? ";
  uint32_t position_of_first_element, position_of_second_element;
  std::cin >> position_of_first_element >> position_of_second_element;
  ar.swap(position_of_first_element, position_of_second_element);
  
  std::cout << "Enter the element you want to replace and new value: ";
  uint32_t pos;
  int value;
  std::cin >> pos >> value;
  ar.replace(pos, value);
  ar.show();
}
