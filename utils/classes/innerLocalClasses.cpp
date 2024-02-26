#include "../utils.hpp"

#include <iostream>

class Container {
  public:
    void setValueParams(int a, int b) {
      instance.a = std::to_string(a);
      instance.b = std::to_string(b);
    }

    void logValue() {
      std::cout << "a: " << instance.a << "; b: " << instance.b << std::endl;
    }

    private:
      class Value {
        public:
          std::string a;
          std::string b;
      };
      Container::Value instance;
};

namespace utils {

  void innerLocalClasses() {
    class InitialValues {
      public:
        int a = 9;
        int b = 2;
    };

    auto c = Container();
    InitialValues values;
    c.setValueParams(values.a, values.b);
    c.logValue();
  }

}
