#include <iostream>
#include <iomanip>
#include "Homework11_matrix.hpp"

Matrix::Matrix (uint32_t SizeOfMatrix) {
  Size = SizeOfMatrix;
  Matrix_arr = new int*[SizeOfMatrix];
  for(size_t i = 0; i < SizeOfMatrix; ++i) {
    Matrix_arr[i] = new int[SizeOfMatrix];
  }
}

Matrix::Matrix (const Matrix &mc) {
  Size = mc.Size;
  Matrix_arr = new int*[Size];
  for(size_t i = 0; i < Size; ++i) {
    Matrix_arr[i] = new int[Size];
  }
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      Matrix_arr[i][j] = mc.Matrix_arr[i][j];
    }
  }
}

int & Matrix::operator() (int row, int col) {
  return Matrix_arr[row][col];
}

Matrix &Matrix::operator= (const Matrix &right) {
  if (this != &right) {
    delete [] Matrix_arr;
    Size = right.Size; 
    Matrix_arr = new int *[Size]; 
    for(size_t i = 0; i < Size; ++i) {
      Matrix_arr[i] = new int[Size];
    }
    for (size_t i = 0; i < Size; ++i) {
      for (size_t j = 0; j < Size; ++j) {
        Matrix_arr[i][j] = right.Matrix_arr[i][j];
      }
    }
  }
  return *this;
}

void Matrix::Fill (int max_value) {
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      Matrix_arr[i][j] = rand () % max_value;
    }
  }
}


Matrix const Matrix::operator+ (const Matrix& val) {
  Matrix result(*this);
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      result.Matrix_arr[i][j] = Matrix_arr[i][j] + val.Matrix_arr[i][j];
    }
  }
  return result;
}

Matrix const Matrix::operator+= (const Matrix& val) {
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      Matrix_arr[i][j] = Matrix_arr[i][j] + val.Matrix_arr[i][j];
    }
  }
  return *this;
}

Matrix const Matrix::operator- (const Matrix& val) {
  Matrix result(*this);
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      result.Matrix_arr[i][j] = Matrix_arr[i][j] - val.Matrix_arr[i][j];
    }
  }
  return result;
}
Matrix const Matrix::operator-= (const Matrix& val) {
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      Matrix_arr[i][j] = Matrix_arr[i][j] - val.Matrix_arr[i][j];
    }
  }
  return *this;
}

Matrix const Matrix::operator* (Matrix &val) {
  Matrix tmp(Size);
  Matrix result(*this);
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      tmp(i, j) = 0;
      for (size_t k = 0; k < Size; ++k) {
        tmp(i, j) += result(i, k) * val(k, j);
      }
    }
  }
  return tmp;
}

Matrix const Matrix::operator*= (Matrix &val) {
  Matrix tmp(Size);
  Matrix result(*this);
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      tmp(i, j) = 0;
      for (size_t k = 0; k < Size; ++k) {
        tmp(i, j) += result(i, k) * val(k, j);
      }
    }
  }
  return tmp;
}

const Matrix Matrix::operator* (int scalar) {
  Matrix result(*this);
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      result.Matrix_arr[i][j] = Matrix_arr[i][j] * scalar;
    }
  }
  return result;
}

const Matrix Matrix::operator*= (int scalar) {
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      Matrix_arr[i][j] = Matrix_arr[i][j] * scalar;
    }
  }
  return *this;
}

void Matrix::show() const {
  std::cout << "Matrix: \n";
  for (size_t i = 0; i < Size; ++i) {
    for (size_t j = 0; j < Size; ++j) {
      std::cout << std::setw(3) << Matrix_arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

Matrix::~Matrix() {
  for(size_t i = 0; i < Size; ++i) {
    delete [] Matrix_arr[i];
  }
  delete [] Matrix_arr;
}