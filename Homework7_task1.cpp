#include <iostream>
#include <string>
struct Array {
  int add_element (int value);
  int replace (uint32_t position_of_el, int new_value);
  int swap (uint32_t first_pos, uint32_t second_pos);
  void show () const;
  constexpr static unsigned ARRAY_SIZE = 255;
  int array[ARRAY_SIZE] {};
  int position = 0;
};

int Array::add_element (int value) {
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

int main () {
  Array arr;
  std::cout << "How much elements you want to enter? ";
  uint32_t num;
  std::cin >> num;
  while (num != 0) {
    int value;
    std::cin >> value;
    arr.add_element(value);
    --num;
  }
  std::cout << "Which elements you want to swap? ";
  uint32_t position_of_first_element, position_of_second_element;
  std::cin >> position_of_first_element >> position_of_second_element;
  arr.swap(position_of_first_element, position_of_second_element);
  
  std::cout << "Enter the element you want to replace and new value: ";
  uint32_t pos;
  int value;
  std::cin >> pos >> value;
  arr.replace(pos, value);
  arr.show();
}
