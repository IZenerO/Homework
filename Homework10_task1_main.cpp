#include <iostream>
#include "Homework10_task1_shape.hpp"

void create (Shape & sh) {
  sh.calc_area();
  sh.draw();
}

int main () {
  Square sq;
  create(sq);
  Rectangle rc;
  create(rc);
  Triangle tr;
  create(tr);
}