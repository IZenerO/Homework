#include <iostream>
#include "Homework11_matrix.hpp"

Matrix::Matrix (int SizeOfMatrix) {
  Size = SizeOfMatrix;
  int **Matrix_arr = new int*[SizeOfMatrix];
  for(int i = 0; i < SizeOfMatrix; ++i) {
    Matrix_arr[i] = new int[SizeOfMatrix];
  }
}
Matrix::Matrix (const Matrix &mc) {
  Matrix_arr = new int*[Size];
  for(int i = 0; i < Size; ++i) {
    Matrix_arr[i] = new int[Size];
    for (int i = 0; i < Size; ++i) {
      for (int j = 0; j < Size; ++j) {
        Matrix_arr[i][j] = mc.Matrix_arr[i][j];
      }
    }
  }
}

int & Matrix::operator() (int row, int col) {
  std::cout << row << " " << col << " " << "Operator() call ";
  return Matrix_arr[row][col];
}

const int Matrix::GetSize () const {
  return Size;
}

// void Matrix::Fill (int max_value) {
//   for (int i = 0; i < Size; ++i) {
//     for (int j = 0; j < Size; ++j) {
//       Matrix_arr[i][j] = rand () % max_value;
//     }
//   }
// }

Matrix const Matrix::operator+ (const Matrix& val) {
  Matrix result(*this);
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      result.Matrix_arr[i][j] += val.Matrix_arr[i][j];
    }
  }
  return result;
}

Matrix const Matrix::operator- (const Matrix& val) {
  Matrix result(*this);
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      result.Matrix_arr[i][j] -= val.Matrix_arr[i][j];
    }
  }
  return result;
}

void Matrix::show() {
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      std::cout << Matrix_arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
Matrix::~Matrix() {
  for(int i = 0; i < Size; ++i) {
    delete [] Matrix_arr[i];
  }
  delete [] Matrix_arr;
}