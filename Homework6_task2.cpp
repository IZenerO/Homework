#include <iostream>
#include <functional>
#include <time.h> 

using comparator = std::function<bool(int a, int b)>;

void bubble_sort (int *start, int size, comparator (comp)) {
  size_t temp = 0;
  for (int i = 0; i < size - 1; ++i) {
    for(int j = 0; j < size - 1; ++j) {
      if (comp(*(start + j), *(start + j + 1))) {
        temp = *(start + j);
        *(start + j) = *(start + j + 1);
        *(start + j + 1) = temp;
      }
    }
  }
}
void quickSort(int *mas, int first, int last) {
  uint32_t mid, temp;
  uint32_t f = first, l = last;
  mid = mas[(f + l) / 2];
  while (f < l) {
    while (mas[f] < mid) {
      f++;
    }
    while (mas[l] > mid) {
      l--;
    }
    if (f <= l) {
      temp = mas[f];
      mas[f] = mas[l];
      mas[l] = temp;
      f++;
      l--;
    }
  };
  if (first < l) {
    quickSort(mas, first, l); 
  }
  if (f < last) {
    quickSort(mas, f, last);
  }
}
void show (int arr[], uint32_t size) {
  for (uint32_t i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main () {
  const uint32_t ARRAY_SIZE = 200;
  clock_t t = clock();

  int first_array[ARRAY_SIZE] {};
  int second_array[ARRAY_SIZE] {};

  int *begin_of_first = first_array;
  int *end_of_first = first_array + ARRAY_SIZE;
  

  for (size_t i = 0; i < ARRAY_SIZE; ++i) {
    first_array[i] = rand() % 1000;
  }
   for (size_t i = 0; i < ARRAY_SIZE; ++i) {
    second_array[i] = rand() % 1000;
  }
  
  std::cout << "Unsorted\n";
  show(first_array, ARRAY_SIZE);
  bubble_sort(begin_of_first, ARRAY_SIZE, [](int a, int b) {return a < b;});
  std::cout << "Bubble sort\n";
  show(first_array, ARRAY_SIZE);
  std::cout << "Bubble sort time:" << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << std::endl;
 

  std::cout << "Unsorted\n";
  show(second_array, ARRAY_SIZE);
  quickSort(second_array, 0, ARRAY_SIZE - 1);
  std::cout << "Quick sort\n";
  show(second_array, ARRAY_SIZE);
  std::cout << "Quick sort time:" << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << std::endl;
  return 0;
}