#include <iostream>

struct Hash {
  int key;
  uint32_t num;
  uint32_t count;
};

int HashFunction(uint32_t k, uint32_t cnt) {
  return (k%cnt);
}

int main() {
  Hash hs;
  std::cout << "How much keys you want to enter?" << std::endl;
  std::cin >> hs.num;
  std::cout << "Maximum numbers of hash-codes? " << std::endl;
  std::cin >> hs.count;
  while (hs.num != 0) {
    std::cout << "Your key: ";
    std::cin >> hs.key;
    std::cout << "HashFunction(" << hs.key <<")=" << HashFunction(hs.key, hs.count) << std::endl;
    --hs.num;
  }
}