#include <iostream>

int main () {

  std::cout << "Enter number above 0: ";
  uint32_t user_num;
  std::cin >> user_num;
  uint32_t count = 1;
  const uint32_t NUM = user_num;
  const uint32_t DIVIDER = 10;

  while ((user_num /= DIVIDER) > 0){
    count++;
  }
  
  if (NUM > 0) {
    uint32_t sum = 0;
    uint32_t remainder = 1;
    for (int i = 0; i < count; i++) {
      uint32_t temp = 0;
      temp = (NUM / remainder) % 10;
      sum += temp;
      remainder *= DIVIDER;
    }
    double AVERAGE = static_cast<double>(sum) / count;
    std::cout << AVERAGE;
  } else {
    std::cout << "You entered wrong number!";
  }
  return 0;
}