#pragma once

class Vector {
  public:
    const int GetElement (const int num) const;
    const int GetSize () const;
    void PushElement (int new_element);
    void InsertElement (int position, int value);
    void show (Vector & vector);
    int front () const;
    int back () const;
    Vector ();
    Vector (int size);
    Vector (const Vector& vector);
    ~Vector ();
  private:
    int* array = nullptr;
    int VECTOR_SIZE;
};