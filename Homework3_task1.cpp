#include <iostream>

int main () {
  int number_of_stars;
  std::cout << "Please, enter number of stars: " << std::endl;
  std::cin >> number_of_stars;
  if (number_of_stars > 1) {
    uint32_t avg = number_of_stars / 2;
    uint32_t start_of_line = avg;
    uint32_t end_of_line = avg;

    while (start_of_line >= 0) {
      for (int i = 0; i < start_of_line; i++) {
        std::cout << " ";
      }
      for (int i = start_of_line; i <= end_of_line; i++) {
        std::cout << "*";
      }
      start_of_line--;
      end_of_line++;
      std::cout << std::endl;
    }
  }
  return 0;
}