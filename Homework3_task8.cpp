#include <iostream>

int main () {
  std::cout << "Enter your number" << std::endl;
  uint32_t user_num;
  std::cin >> user_num;
  const uint32_t DIVIDER = 10;
  size_t i = 1;
  uint32_t max_divider = 0;
  uint32_t sum_divider; 

  while (i < user_num) {
    if (user_num % i == 0) {
      max_divider = i;
    }
    if (i >= 10 && user_num % i == 0) {
      sum_divider = 0;
      uint32_t count_temp = i;
      while (count_temp != 0) {
        sum_divider += count_temp % 10;
        count_temp /= DIVIDER; 
      }
    }
    i++;
  }

  uint32_t sum = 0;
  const uint32_t NUM = user_num;
  while (user_num != 0) {
    sum += user_num % 10;
    user_num /= DIVIDER;
  }
  if (sum > sum_divider) {
    std::cout << "Max divider: " << NUM;
  } else {
    std::cout << "Max divider: " << max_divider;
  }
}