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

bool Array::bubble_sort () {
  int temp = 0;
  for (uint32_t i = 0; i < ARRAY_SIZE - 1; ++i) {
    for(uint32_t j = 0; j < ARRAY_SIZE - 1; ++j) {
      if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  return true;
}

int Array::get_value(uint32_t position) {
  if (position > ARRAY_SIZE || position < 0) {
    std::cout << "Element with this position doesn't exist!";
  } else {
    std::cout << "Element with this position is: " << array[position];
  }
  return array[position];
}