#include <iostream>

int main () {
  std::cout << "Enter number above 0 to calculate a number of setted bits: " << std::endl;
  uint32_t num;
  std::cin >> num;
  uint32_t count = 0;
  while (num != 0) {
    count += num & 1;
    num >>= 1;
  }
  std::cout << "Number of setted bits is: " << count;
  return 0;
}