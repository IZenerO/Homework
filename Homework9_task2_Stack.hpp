#pragma once
#include "Homework9_task2_vector.hpp"

class Stack : private Vector {
  public:
    const int Stack_Get_element (const int num) const;
    const int Stack_Get_size () const;
    void Stack_Push_el (int el);
    void Stack_insert_el (int pos, int val);
    void stack_show (Stack & st);
    int stack_front () const;
    int stack_back () const;
    Stack(int size);
    Stack(const Stack& st);
    Stack() = delete;
    ~Stack();
  private:
    int* array;
    int STACK_SIZE;
};