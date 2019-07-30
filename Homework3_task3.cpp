#include <iostream>

int main () {
  std::cout << "Enter number above 0: " << std::endl;
  uint32_t num;
  std::cin >> num;
  uint32_t count = 0;
  while (num != 0) {
    if (num & 1) {
      count++;
    }
    num >>= 1;
  }
  std::cout << std::endl;
  std::cout << count << std::endl;
  return 0;
}