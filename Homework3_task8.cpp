#include <iostream>

int main () {
  std::cout << "Enter your number" << std::endl;
  uint32_t user_num;
  std::cin >> user_num;
  const uint32_t NUM = user_num;
  const uint32_t DIVIDER = 10;
  uint32_t count = 1;
  uint32_t sum = 0;
  uint32_t remainder = 1;
  uint32_t max_divider = 0;
  while ((user_num /= DIVIDER) > 0){
    count++;
  }
  for (int i = 0; i < count; i++) {
    uint32_t temp = 0;
    temp = (NUM / remainder) % 10;
    sum += temp;
    remainder *= DIVIDER;
  }
  std::cout << "Max divider: ";
  for (int i = 1; i < NUM; ++i) {
    if (NUM % i == 0) {
      max_divider = i;
    } else {
      continue;
    }
  }
  std::cout << max_divider;
}