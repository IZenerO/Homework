#include <iostream>

int main () {
  const uint32_t ARRAY_SIZE = 50;
  std::cout << "Enter your string to convert it in lower register: ";
  char user_str [ARRAY_SIZE];
  std::cin >> user_str;

  char *begin = user_str;
  char *end = user_str + ARRAY_SIZE;
  char count = 0;
  std::cout << "Your string in lower register: ";
  while (begin != end) {
    if (*begin >= 'A' && *begin <= 'Z') {
      *begin += 'a' - 'A';
      std::cout << *begin;
    } else {
      std::cout << *begin;
    }
    *(begin++) = ++count;
  }
}