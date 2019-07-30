#include <iostream>

int main () {
  while (true) {
    std::cout << "How much numbers you want to enter? " << std::endl;
    uint32_t count_num;
    std::cin >> count_num;

    std::cout << "Please, enter your numbers: " << std::endl;
    uint32_t num;
    uint32_t sum = 0;
    for (int i = 0; i < count_num; i++) {
      std::cin >> num;
      sum += num;
    }
    if (sum % 3 == 0) {
      std::cout << "Yes" << std::endl;
      break;
    } else {
      std::cout << "No" << std::endl;
      continue;
    }
  }
  return 0;
}