#include <iostream>
#include <functional>

using comparator = std::function<bool(int a, int b)>;
template <class T>
void bubble_sort (T *arr, uint32_t size, comparator comp) {
  if(nullptr == arr) {return;}
  T temp = 0;
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
void show (int arr[], uint32_t size) {
  for (uint32_t i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
int main () {
  const uint32_t ARRAY_SIZE = 200;
  int first_array[ARRAY_SIZE] {};

  for (size_t i = 0; i < ARRAY_SIZE; ++i) {
    first_array[i] = rand() % 1000;
  }
  std::cout << "Bubble sort\n";
  bubble_sort(first_array, ARRAY_SIZE, [](int a, int b) {return a < b;});
  show(first_array, ARRAY_SIZE);
}