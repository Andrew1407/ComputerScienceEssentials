#include "sorting.hpp"

namespace sorting {
  void selectionSort(int* array, int length) {
    for (int i = 0; i < length - 1; ++i) {
      int minIdx = i;
      int current = array[i];
      for (int u = i + 1; u < length; ++u)
        if (current > array[u]) minIdx = u;
      array[i] = array[minIdx];
      array[minIdx] = current;
    }
  }
}
