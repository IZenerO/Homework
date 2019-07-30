#include <iostream>

int main () {
  while (true) {
    std::cout << "How much numbers you want to enter? " << std::endl;
    uint32_t count_num;
    std::cin >> count_num;
    if (count_num > 50) {
      std::cout << "Please, enter less than 50 numbers!" << std::endl;
      continue;
    }
    const int32_t LOW_RANGE_VALUE = -60;
    const int32_t HIGH_RANGE_VALUE = 90;
    std::cout << "Please, enter your numbers in range " << LOW_RANGE_VALUE << "..." << HIGH_RANGE_VALUE << std::endl;
    int32_t num;
    int32_t sum = 0;
    for (int i = 0; i < count_num; i++) {
      std::cin >> num;
      if (num <= LOW_RANGE_VALUE || num >= HIGH_RANGE_VALUE) {
      std::cout << "You entered number out of range!" << std::endl;
      i--;
      continue;
    }
      std::cout << std::endl;
      if (num % 2 != 0) {
        sum += num;   
      }
    }
    std::cout << "Sum of the odd numbers: " << sum;
    break;
  }
}