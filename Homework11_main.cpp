#include <iostream>
#include "Homework11_matrix.hpp"

int main () {
  std::cout << "Enter size of first and second matrix: ";
  uint32_t size1, size2;
  std::cin >> size1 >> size2;
  Matrix m{size1}, m1{size1};
  std::cout << "Sum of 2 matrix:\n";
  m.Fill(100);
  m1.Fill(100);
  m.show();
  m1.show();
  m += m1;
  m.show();
  Matrix m_diff{size1}, m_diff1{size2};
  std::cout << "Difference between 2 matrix:\n";
  m_diff.Fill(100);
  m_diff1.Fill(100);
  m_diff.show();
  m_diff1.show();
  m_diff -= m_diff1;
  m_diff.show();
  Matrix m_mult{size1}, m_mult1{size2};
  std::cout << "Multiplication of 2 matrix:\n";
  m_mult.Fill(100);
  m_mult1.Fill(100);
  m_mult.show();
  m_mult1.show();
  m_mult = m_mult * m_mult1;
  m_mult.show();
  Matrix m_mult_num{size1};
  std::cout << "Multiplication of matrix and your nubmer:\n";
  m_mult_num.Fill(100);
  m_mult_num.show();
  std::cout << "Enter number to multiple it on a matrix: ";
  uint32_t num;
  std::cin >> num;
  m_mult_num *= num;
  m_mult_num.show();
}