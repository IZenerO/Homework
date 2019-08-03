#include <iostream>

int main () {
  while (true) {
    std::cout << "How much numbers you want to enter? " << std::endl;
    uint32_t count_num;
    std::cin >> count_num;
    const uint32_t MAX_NUMBERS = 50;
    if (count_num > MAX_NUMBERS) {
      std::cout << "Please, enter less than " << MAX_NUMBERS << " numbers!" << std::endl;
      continue;
    }
    const int32_t LOW_RANGE_VALUE = -60;
    const int32_t HIGH_RANGE_VALUE = 90;
    std::cout << "Please, enter your numbers in range " << LOW_RANGE_VALUE << "..." << HIGH_RANGE_VALUE << std::endl;
    int32_t sum = 0;
    size_t i = 0;
    while (i != count_num) {
      int32_t num;
      std::cin >> num;
      ++i;
      if (num <= LOW_RANGE_VALUE || num >= HIGH_RANGE_VALUE) {
        std::cout << "You entered number out of range!" << std::endl;
        --i;
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