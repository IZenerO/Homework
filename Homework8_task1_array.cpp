#include <iostream>
#include "Homework8_task1_array.hpp"

int Array::add(int value) {
  if (position == ARRAY_SIZE) {
    std::cout << "Array is full\n";
    return 0;
  }
  array[position++] = value;
  return array[position];
}

int Array::replace (uint32_t position_of_el, int new_value) {
  if (position_of_el > ARRAY_SIZE) {
    std::cout << "Out of range!\n";
    return 0;
  }
  array[position_of_el - 1] = new_value;
  return array[position];
}

int Array::swap (uint32_t first_pos, uint32_t second_pos) {
  if (first_pos > ARRAY_SIZE || second_pos > ARRAY_SIZE) {
    std::cout << "Out of range!\n";
    return 0;
  }
  uint32_t temp = array[first_pos - 1];
  array[first_pos - 1] = array[second_pos - 1];
  array[second_pos - 1] = temp; 
  return array[position]; 
}

void Array::show () const {
  for (uint32_t i = 0; i < ARRAY_SIZE; ++i) {
    std::cout << array[i] << " ";
  }
}