#include "sorting.hpp"
#include <iostream>

namespace sorting {
  void bubbleSort(int* array, int length) {
    bool wasSwapped;
    do {
      wasSwapped = false;
      for (int i = 0; i < length - 1; ++i) {
        int nextIdx = i + 1;
        int current = array[i];
        int next = array[nextIdx];
        bool shouldSwap = current > next;
        wasSwapped = wasSwapped || shouldSwap;
        if (shouldSwap) {
          array[i] = next;
          array[nextIdx] = current;
        }
      }
    } while (wasSwapped);
  }
}
