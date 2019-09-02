#include <iostream>
#include <functional>
#include <chrono> 

using comparator = std::function<bool(int a, int b)>;

void bubble_sort (int *arr, uint32_t size, comparator comp) {
  int temp = 0;
  for (uint32_t i = 0; i < size - 1; ++i) {
    for(uint32_t j = 0; j < size - 1; ++j) {
      if (comp(arr[j], arr[j + 1])) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
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
  auto start_bubblesort = std::chrono::steady_clock::now();
  bubble_sort(first_array, ARRAY_SIZE, [](int a, int b) {return a < b;});
  auto end_bubblesort = std::chrono::steady_clock::now();
  std::chrono::duration<double> diff = end_bubblesort-start_bubblesort;
  std::cout << "Bubble sort\n";
  show(first_array, ARRAY_SIZE);
  std::cout << "Bubble sort time:" << diff.count() << std::endl;
 

  std::cout << "Unsorted\n";
  show(second_array, ARRAY_SIZE);
  auto start_for_quicksort = std::chrono::steady_clock::now();
  quickSort(second_array, 0, ARRAY_SIZE - 1);
  auto end_for_quicksort = std::chrono::steady_clock::now();
  std::chrono::duration<double> diff_quicksort = end_for_quicksort-start_for_quicksort;
  std::cout << "Quick sort\n";
  show(second_array, ARRAY_SIZE);
  std::cout << "Quick sort time:" << diff_quicksort.count() << std::endl;
  return 0;
}