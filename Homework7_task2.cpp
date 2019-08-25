#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

std::string revrot (std::string str, uint32_t sz) {
  if (str.empty()) {
    std::cout << "Your string is empty!";
    return 0;
  }
  if (sz <= 0) {
    std::cout << "Your size is less or equal to zero!";
    return 0;
  }
  uint32_t count = str.length() / sz;
  uint32_t pos = 0;
  std::string result;
  while (count != 0) {
    std::string str_changed = str.substr(pos, sz); 
    result.reserve(str_changed.size());
    uint32_t int_str = std::stoi(str_changed.c_str());
    uint32_t temp = 0;
    for (uint32_t i = 0; i < sz; ++i) {
      temp += pow(int_str % 10, 3);
      int_str /= 10;
      ++pos;
    }
    if (temp % 2 == 0) {
      std::reverse(str_changed.begin(), str_changed.end());
      result += str_changed;
    } else {
      for (uint32_t sub = 1; sub < str_changed.length(); ++sub) {
        result += str_changed[sub];
      }
      result += str_changed[0];
    }
    --count;
  }
  return result;
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

