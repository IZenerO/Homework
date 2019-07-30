#include <iostream>

int main () {
  std::cout << "Enter you number: ";
  int32_t user_number;
  std::cin >> user_number;
  int32_t num = user_number;
  int32_t remainder = 1;
  const int32_t DIVIDER = 10;
  uint32_t count = 1;
  
  while ((user_number /= DIVIDER) != 0) {
    count++;
  }
  for (int i = 0; i < count; i++) {
    int32_t temp_num = 0;
    temp_num = (num / remainder ) % 10;  
    int32_t reverse_number = temp_num;
    remainder *= DIVIDER;
    if (i >= 1) {
      std::cout << abs (reverse_number);
    } else {
      std::cout <<  reverse_number;
    }
  }
}