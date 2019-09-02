#include <iostream>

size_t arr_len (const char* temp) {
  size_t count = 0;
  while (*temp++) {
    ++count;
  }
  return count;
}

void crypt (char *start, const char *end, uint32_t key) {
  if(start != nullptr && end != nullptr && start != end && key > 0) {
    while (start != end) {
      *start = *start + key;
      ++start;
    }
  }
}
void decrypt (char *start, const char *end, uint32_t key) {
  if(start != nullptr && end != nullptr && start != end && key > 0) {
    while (start != end) {
      *start = *start - key;
      ++start;
    }
  }
}

int main () {
  const uint32_t ARRAY_SIZE = 30;
  std::cout << "Enter your string to crypt it: ";
  char array[ARRAY_SIZE] {};
  std::cin >> array;
  std::cout << "Enter your key: ";
  uint32_t key;
  std::cin >> key;

  char *begin = array;
  char *end = array + arr_len(array);

  crypt(begin, end, key);
  std::cout << "Your crypted string: " << array << std::endl;

  std::cout << "Enter received key to decrypt string: " << std::endl;
  uint32_t decr_key;
  std::cin >> decr_key;
  if (decr_key != key) {
    std::cout << "You key is incorrect, unable to decrypt string";
    return 0;
  }
  decrypt(begin, end, decr_key);
  std::cout << "Your decrypted string: " << array; 
}