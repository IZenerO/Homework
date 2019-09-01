#include <iostream>
#include "Homework11_matrix.hpp"

int main () {
  Matrix m{10};
  for (int i = 0; i < m.GetSize(); ++i) {
    for (int j = 0; j < m.GetSize(); ++j) {
      std::cout << i << " " << j << " " << "m.GetSize() = " << m.GetSize() <<" loop call ";
      m(i,j) = 20;
      std::cout << i << " " << j << " " << "loop call ";
    }
  }
  // m(0,0) = 5;
  // std::cout << m(0,0);
  //m.show();
}