#include "utils.hpp"
#include <iostream>
#include "../sorting/sorting.hpp"

namespace utils {
  void useSorting() {
    int arr[6] = { 1, -90, 4, 2, 1, 10 };
    sorting::bubbleSort(arr, 6);

    for (const auto& el : arr) std::cout << el << std::endl;
  }
}

