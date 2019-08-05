#include <iostream>

int main () {
  const uint32_t ARRAY_SIZE = 50;
  std::cout << "Enter your string to check it for numbers: ";
  char user_str [ARRAY_SIZE] {};
  std::cin >> user_str;

  char *begin = user_str;
  char *end = user_str + ARRAY_SIZE;
  std::cout << "Numbers in your string are: ";
  while (begin != end && *begin != '\0') {
    if (*begin >= '0' && *begin <= '9') {
      std::cout << *begin << " ";
    }
    ++begin;
  }
}