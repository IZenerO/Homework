#include <iostream>
#include <cstring>
#include <cmath>

std::string reverse (std::string &str1) {
  char temp_for_reverse[str1.length()] {};
  strcpy(temp_for_reverse, str1.c_str());
  char *begin = temp_for_reverse;
  char *end = temp_for_reverse + (str1.length() - 1);
  uint32_t mid = str1.length() / 2;
  while (mid != 0) {
    char temp = *begin;
    *begin = *end;
    *end = temp;
    ++begin;
    --end;
    --mid;
  }
  return std::string(temp_for_reverse);
}

std::string move_left (std::string &str2) {
  char temp_for_move[str2.length()] {};
  strcpy(temp_for_move, str2.c_str());
  char *begin = temp_for_move;
  char *next_begin = temp_for_move + 1;
  char *end = temp_for_move + (str2.length() - 1);
  while (begin != end) {
    char temp = *begin;
    *begin = *next_begin;
    *next_begin = temp;
    ++begin;
    ++next_begin;
  }
  return std::string(temp_for_move);
}
std::string revrot (const std::string &str, uint32_t sz) {
  if (str.length() == 0) {
    std::cout << "Your string is empty!";
  } else if (sz <= 0) {
    std::cout << "Your size is less or equal to zero!";
  } else {
    uint32_t count = str.length() / sz;
    std::string main_str;
    uint32_t pos = 0;
    while (count != 0) {
      std::string str_changed = str.substr(pos, sz);
      uint32_t int_str = atoi(str_changed.c_str());
      uint32_t temp = 0;
      for (int i = 0; i < sz; ++i) {
        temp += pow(int_str % 10, 3);
        int_str /= 10;
        ++pos;
      }
      if (temp % 2 == 0) {
        main_str += reverse(str_changed);
      } else {
        main_str += move_left(str_changed);
      }
        --count;
    }
    return main_str;
  }
  return 0;
}

int main () {
  std::cout << "Enter your string to reverse or rotate it: ";
  std::string user_str;
  std::getline(std::cin, user_str);
  std::cout << "Size of your substring: ";
  uint32_t size;
  std::cin >> size;
  std::cout << "Your modified string: " << revrot(user_str, size);
}