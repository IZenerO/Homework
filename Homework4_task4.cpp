#include <iostream>

void swap(char &start, char &end)
{
  char temp = start;
  start = end;
  end = temp;
}
int arr_len (const char* temp) {
  const char* current = temp;
  for (; *current; ++current);
  return current - temp;
}

int main () {
  const uint32_t ARRAY_SIZE = 300;
  std::cout << "Enter your string to revers it: ";
  char user_str [ARRAY_SIZE];
  std::cin >> user_str;

  char *begin = user_str;
  char *end = user_str + ARRAY_SIZE;
  char *end_of_array = user_str + (ARRAY_SIZE - 1);
  int len = arr_len(begin);
  while (begin <= end_of_array) {
    auto& ch_first = *begin++;
    auto& ch_second = *end_of_array--;
    swap(ch_first, ch_second);
  }
  begin = user_str + (ARRAY_SIZE - len);
  while (begin != end) {
    std::cout << "Your reversed string: " << *begin;
    begin++;
  }
}