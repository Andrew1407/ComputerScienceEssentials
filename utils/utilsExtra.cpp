#include "utils.hpp"
#include <iostream>
#include <functional>

int f(int a, int b) { return a + b; }

namespace utils {
  void callFunction() {
    // int (*fn)(int, int) = f;
    int (*fn)(int, int) = [] (int a, int b) { return a + b; };
    // std::function<int(int, int)> fn = [] (int a, int b) { return a + b; };
    std::cout << fn(3, 4) << std::endl;
  }
}

