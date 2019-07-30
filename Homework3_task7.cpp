#include <iostream>

int main () {
  std::cout << "Enter number above 0: " << std::endl;
  uint32_t num;
  std::cin >> num;
  std::cout << "Enter number to check bit: " << std::endl;
  uint32_t check_num;
  std::cin >> check_num;
  uint32_t count =0;
  while (num != 0) {
    if (num & 1) {
      count++;
    }
    num >>= 1;
    if (count == check_num) {
      std::cout << "Yes";
      return 0;
    } else {
      continue;
    }
  }
  std::cout << "No";
  return 0;
}