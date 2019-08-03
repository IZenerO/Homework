#include <iostream>

int main () {
  const uint32_t ARRAY_SIZE = 50;
  std::cout << "Enter your string to convert it in upper register: ";
  char user_str [ARRAY_SIZE];
  std::cin >> user_str;

  char *begin = user_str;
  char *end = user_str + ARRAY_SIZE;
  std::cout << "Your string in upper register: ";
  const char TO_UPPER = 'A' - 'a'; 
  while (begin != end && *begin != '\0') {
    char& ch = *begin;
    if (ch >= 'a' && ch <= 'z') {
      ch += TO_UPPER;
    }
    std::cout << ch; 
    ++begin;
  }
}