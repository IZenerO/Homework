#include <iostream>

int main () {
  while (true) {
    std::cout << "Enter amount of numbers you want to work with: " << std::endl;
    uint32_t count_num;
    std::cin >> count_num;

    std::cout << "Please, enter your numbers: " << std::endl;
    unsigned long int sum = 0;
    for (size_t i = 0; i < count_num; i++) {
      uint32_t num;
      std::cin >> num;
      sum += num;
    }
    if (sum % 3 == 0) {
      std::cout << "Yes" << std::endl;
      break;
    } else {
      std::cout << "No" << std::endl;
    }
  }
  return 0;
}