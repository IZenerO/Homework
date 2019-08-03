#include <iostream>

int main () {
  std::cout << "Enter number above 0 to check it for setted bit: " << std::endl;
  uint32_t num;
  std::cin >> num;
  std::cout << "Enter number to check setted bit: " << std::endl;
  uint32_t check_num;
  std::cin >> check_num;
  num >>= check_num - 1;
  if (num & 1) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
  return 0;
}
