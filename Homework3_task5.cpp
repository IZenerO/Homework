#include <iostream>

int main () {
  std::cout << "Enter you number to reverse it: ";
  int32_t user_number;
  std::cin >> user_number;
  const int32_t DIVIDER = 10;
  int32_t reverse_value = 0;

  while (user_number != 0) {
    reverse_value = reverse_value * 10 + user_number % 10;
    user_number /= DIVIDER;
  }
  std::cout << "Your reversed number: " << reverse_value;
}