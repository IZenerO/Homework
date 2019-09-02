#include <iostream>
#include "Homework9_task2_vector.hpp"


Vector::Vector()
: VECTOR_SIZE(0) {
  array = nullptr;
}

Vector::Vector (int size) 
: VECTOR_SIZE(size) {
  array = new int[VECTOR_SIZE];
  for(int i = 0; i < VECTOR_SIZE; ++i) {
    array[i] = 0;
  }                     
}

Vector::Vector (const Vector & vector) 
: VECTOR_SIZE(vector.VECTOR_SIZE) {
  array = new int[VECTOR_SIZE];
  for(int i = 0; i < VECTOR_SIZE; ++i) {
    array[i] = vector.GetElement(i);
  }
}

const int Vector::GetSize () const {
  return VECTOR_SIZE;
}
const int Vector::GetElement (const int num) const {
  if(num < 0 || VECTOR_SIZE <= 0) {
    return -1;
  }
  int fd = array[num];
  return fd;
}
void Vector::PushElement(int new_element) {
  int *temp_arr = new int[VECTOR_SIZE + 1];
  for(int i = 0; i < VECTOR_SIZE; ++i) {
    temp_arr[i] = array[i];
  }
  delete[] array;
  temp_arr[VECTOR_SIZE++] = new_element;
  array = temp_arr;
  temp_arr = nullptr;
}
void Vector::InsertElement (int position, int value) {
  if(position < VECTOR_SIZE && position >= 0)
  array[position] = value;
}

int Vector::front () const{
  return array[0];
}
int Vector::back () const{
  return array[VECTOR_SIZE - 1];
}
void Vector::show (Vector & vector) {
  for (int i = 0; i < vector.GetSize(); ++i) {
    std::cout << i << " = " << vector.GetElement(i) << std::endl;
  }
}
Vector::~Vector() {
  delete[] array;
  array = NULL;
  VECTOR_SIZE = 0;
}