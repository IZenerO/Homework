#include <iostream>
#include "Homework9_task2_Stack.hpp"

Stack::Stack(int size)
: STACK_SIZE(size) {
  if (STACK_SIZE > 0) {
    array = new int [STACK_SIZE]{};
  }
}

Stack::Stack(const Stack& st)
 : Stack(st.STACK_SIZE) {
}

const int Stack::Stack_Get_element(const int num) const{
  return GetElement (num);
}

const int Stack::Stack_Get_size () const {
  return GetSize();
}

void Stack::Stack_Push_el (int el) {
  return PushElement (el);
}


void Stack::Stack_insert_el (int el, int val) {
  return InsertElement (el, val);
}
void Stack::stack_show (Stack & st) {
  return show (st);
} 
int Stack::stack_front () const{
  return front();
}
int Stack::stack_back () const{
  return back();
}
Stack::~Stack() {
  if (array != nullptr) {
    delete [] array;
  }
}