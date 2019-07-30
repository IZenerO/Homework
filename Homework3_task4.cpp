#include <iostream>

int main () {
  while (true) {
    std::cout << "Enter 6 digit number above 0: ";
    uint32_t user_num;
    std::cin >> user_num;
    uint32_t count = 1;
    const uint32_t NUM = user_num;
    uint32_t first_three_sum = 0;
    uint32_t last_three_sum = 0;
    uint32_t remainder = 1;
    const uint32_t DIVIDER = 10;
    const uint32_t MAX_NUMBER_OF_DIGITS = 6;

    while ((user_num /= DIVIDER) > 0) {
      count++;
    }
    const uint32_t MID = count / 2;

    if (NUM < 0 || count < MAX_NUMBER_OF_DIGITS || count > MAX_NUMBER_OF_DIGITS) {
      std::cout << "You entered wrong number!" << std::endl;
      continue;
    }
    for (int i = 0; i < MID; i++) {
      uint32_t temp = 0;
      temp = (NUM / remainder) % 10;
      first_three_sum += temp;
      remainder *= DIVIDER;
    }
    for (int i = 0; i < MID; i++) {
      uint32_t temp = 0;
      temp = NUM / remainder % 10;
      last_three_sum += temp;
      remainder *= DIVIDER;
    }
    if (first_three_sum != last_three_sum) {
      std::cout << "It's an unlucky ticket, better luck next time!" << std::endl;
      continue;
    } 
    if (first_three_sum == last_three_sum) {
      std::cout << "It's a lucky ticket!" << std::endl;
      break;
    }
  }
}
