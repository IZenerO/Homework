#include <iostream>
#include <cmath>
#include "Homework10_task1_shape.hpp"

void Square::calc_area () {
  std::cout << "Input length of one side to calculate area of square: ";
  uint32_t side;
  std::cin >> side;
  uint32_t area_of_square = pow(side, 2);
  std::cout << "The area = " << area_of_square << std::endl;
}

void Rectangle::calc_area () {
  std::cout << "Input length of two sides to calculate area of rectangle: " << std::endl;
  uint32_t side_one, side_two;
  std::cin >> side_one >> side_two;
  uint32_t area_of_rectangle = side_one * side_two;
  std::cout << "The area = " << area_of_rectangle << std::endl;
}

void Triangle::calc_area () {
  std::cout << "Input length of one side and it's heigth to calculate area of triangle: " << std::endl;
  uint32_t side, heigth;
  std::cin >> side >> heigth;
  double area_of_triangle = 0.5 * (side * heigth);
  std::cout << "The area = " << area_of_triangle << std::endl;
}

void Square::draw () const {
  std::cout << "It's Square" << std::endl;
}

void Rectangle::draw () const {
  std::cout << "It's Rectangle" << std::endl;
}

void Triangle::draw () const {
  std::cout << "It's Triangle" << std::endl;
}