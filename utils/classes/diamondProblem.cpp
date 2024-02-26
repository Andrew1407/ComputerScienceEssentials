#include "../utils.hpp"

#include <iostream>

class NumberContainer {
  public:
    int value = 90;
};

class NumberContainer1 : public virtual NumberContainer {};

class NumberContainer2 : public virtual NumberContainer {};

class NumberContainer3 : public NumberContainer1, public NumberContainer2 {};

namespace utils {

  void diamondProblem() {
    NumberContainer3 n;

    n.NumberContainer2::value += 2;
    n.NumberContainer1::value -= 2;

    std::cout << n.NumberContainer2::value << std::endl;
    std::cout << n.NumberContainer1::value << std::endl;
    std::cout << n.value << std::endl;
  }

}
