#include <iostream>

int main () {
  while (true) {
    std::cout << "Is your ticket lucky? Enter 6 digits from your ticket: ";
    uint32_t user_num;
    std::cin >> user_num;
    uint32_t count;
    const uint32_t MAX_NUMBER_OF_DIGITS = 6;
    const uint32_t VALUE = user_num / 100'000;
    if (VALUE >= 1 && VALUE <= 9) {
      count = MAX_NUMBER_OF_DIGITS;
    } else {
      std::cout << "You entered wrong number!" << std::endl;
      continue;
    }
    const uint32_t MID = count / 2;

    if (user_num < 0 || count != MAX_NUMBER_OF_DIGITS) {
      continue;
    }

    uint32_t first_three_sum = 0;
    uint32_t last_three_sum = 0;
    const uint32_t DIVIDER = 10;
    for (size_t i = 0; i < MID; ++i) {
      first_three_sum += user_num % 10;
      user_num /= DIVIDER;
    }
    for (size_t i = 0; i < MID; ++i) {
      last_three_sum += user_num % 10;
      user_num /= DIVIDER;
    }
    if (first_three_sum != last_three_sum) {
      std::cout << "It's an unlucky ticket, better luck next time!" << std::endl;
      continue;
    } else {
      std::cout << "It's a lucky ticket!" << std::endl;
      break;
    }
  }
}