#include <iostream>

int main () {

  std::cout << "Enter number above 0 to calculate average of all digits: ";
  uint32_t user_num;
  std::cin >> user_num;
  uint32_t count = 0;
  const uint32_t DIVIDER = 10;
  uint32_t sum = 0;
  while (user_num != 0) {
    sum += user_num % 10;
    user_num /= DIVIDER;
    count++;
  }
  const double AVERAGE = static_cast<double>(sum) / count;
  std::cout << "Average of all digits is: " << AVERAGE;
  return 0;
}