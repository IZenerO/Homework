#include <iostream>
#include "Homework11_matrix.hpp"

int main () {
  Matrix m{8}, m1 {8};
  m.Fill(100);
  m1.Fill(100);
  m.show();
  //m1.show();
  // m = m + m1;
  // m = m - m1;
  m = m * 5;
  m.show();
}