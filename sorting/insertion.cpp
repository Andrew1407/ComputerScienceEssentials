#include "sorting.hpp"

namespace sorting {
  void insertionSort(int* array, int length) {
    for (int i = 1; i < length; ++i) {
      int current = array[i];
      for (int u = 0; u < i; ++u) {
        if (current >= array[u]) continue;
        int prevoius = array[u];
        for (int j = u + 1; j <= i; ++j) {
          int temp = array[j];
          array[j] = prevoius;
          prevoius = temp;
        }
        array[u] = current;
        break;
      }
    }
  }
}
