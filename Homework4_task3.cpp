#include <iostream>

int main () {
  const uint32_t ARRAY_SIZE = 50;
  std::cout << "Enter your string to convert it in lower register: ";
  char user_str [ARRAY_SIZE];
  std::cin >> user_str;

  char *begin = user_str;
  char *end = user_str + ARRAY_SIZE;
  std::cout << "Your string in lower register: ";
  const char TO_LOWER = 'a' - 'A';
  while (begin != end && *begin != '\0') {
    char& ch = *begin;
    if (ch >= 'A' && ch <= 'Z') {
      ch += TO_LOWER;
    } 
    std::cout << ch; 
    ++begin;
  }
}