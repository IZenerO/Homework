#pragma once

class Matrix {
  public:
    Matrix(uint32_t SizeOfMatrix);
    Matrix(const Matrix &mc);
    ~Matrix();
    void Fill (int max_value);
    int & operator() (int row, int col);
    const Matrix operator+ (const Matrix& val);
    const Matrix  operator+= (const Matrix& val);
    const Matrix operator- (const Matrix& val);
    const Matrix  operator-= (const Matrix& val);
    const Matrix operator* (Matrix &val);
    const Matrix operator*= (Matrix &val);
    const Matrix operator* (int scalar);
    const Matrix operator*= (int scalar);
    Matrix & operator= (const Matrix &right);
    void show () const;
  private:
    int **Matrix_arr;
    uint32_t Size;
};