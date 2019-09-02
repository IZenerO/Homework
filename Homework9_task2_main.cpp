#include <iostream> 
#include "Homework9_task2_vector.hpp"
#include "Homework9_task2_Stack.hpp"

int main () {
  std::cout << "Vector: " << std::endl;
  Vector a;
  a.PushElement(11);
  a.PushElement(22);
  a.PushElement(33);
 
  a.PushElement(44);
  a.PushElement(55);
  a.PushElement(66);
  a.InsertElement(0, 999);
  a.show(a);
  std::cout << "First element of vector: " << a.front() << std::endl;
  std::cout << "Last element of vector: " << a.back() << std::endl;
  std::cout << "Stack: " << std::endl;
  Stack st{10};
  st.Stack_Push_el(10);
  st.Stack_Push_el(20);
  st.Stack_Push_el(30);
  st.Stack_Push_el(40);
  st.Stack_Push_el(50);
  st.Stack_Push_el(60);
  st.Stack_insert_el(5, 150);
  std::cout << "First element of stack: " << st.stack_front() << std::endl;
  std::cout << "Last element of stack: " << st.stack_back() << std::endl;
  st.stack_show(st);

}