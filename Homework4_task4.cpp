#include <iostream>

void swap(char &start, char &end)
{
  char temp = start;
  start = end;
  end = temp;
}
 ptrdiff_t arr_len (const char* temp) {
  size_t count = 0;
  while (*temp++) {
    ++count;
  }
  return count;
}

int main () {
  const uint32_t ARRAY_SIZE = 300;
  std::cout << "Enter your string to revers it: ";
  char user_str [ARRAY_SIZE] = {};
  std::cin >> user_str;

  char *begin = user_str;
  char *end_of_array = user_str + (arr_len(begin) - 1);
  while (begin <= end_of_array) {
    auto& ch_first = *begin++;
    auto& ch_second = *end_of_array--;
    swap(ch_first, ch_second);
  }
   std::cout << user_str << "\n";
}