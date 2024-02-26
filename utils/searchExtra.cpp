#include "utils.hpp"
#include <iostream>

template<typename T>
int linearSearch(T value, T* array, int length) {
  for (int i = 0; i < length; ++i)
    if (array[i] == value) return i;
  return -1;
}

template<typename T>
int binarySearch(T value, T* array, int start, int end) {
  if (start > end) return -1;
  int pivot = (start + end) / 2;
  T pivotValue = array[pivot];
  if (pivotValue == value) return pivot;
  bool pivotGreater = pivotValue > value;
  int startPosition = pivotGreater ? start : pivot + 1;
  int endPosition = pivotGreater ? pivot - 1 : end;
  return binarySearch(value, array, startPosition, endPosition);
}

namespace utils {
  void useLinearSearch() {
    int array[6] = { 1, 3, 7, 15, 30, 123 };
    int idx = linearSearch(7, array, 6);
    std::cout << idx << std::endl;
  }

  void useBinarySearch() {
    int array[6] = { 1, 3, 7, 15, 30, 123 };
    int idx = binarySearch(13, array, 0, 5);
    std::cout << idx << std::endl;
  }
}
