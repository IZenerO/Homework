#pragma once

class Matrix {
  public:
    Matrix(int SizeOfMatrix);
    Matrix(const Matrix &mc);
    ~Matrix();
    void Fill (int max_value);
    const int GetSize () const;
    int & operator() (int row, int col);
    const Matrix operator+ (const Matrix& val);
    const Matrix operator- (const Matrix& val);
    const Matrix operator* (Matrix &val);
    const Matrix operator* (int scalar);
    void Add_Element (int value);
    void show ();
  private:
    int **Matrix_arr;
    int Size;
};