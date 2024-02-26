#include "../utils.hpp"

#include <iostream>

class A {
  public:
    A(int a) {
      std::cout << "a " << a << std::endl;
    }

    virtual void p() {
      std::cout << "bobo" << std::endl;
    }

    ~A() {
      std::cout << "~a " << std::endl;
    }
};

class B : public A {
  public:
    B(int a) : A(a) {
      std::cout << "b " << a << std::endl;
    }

    ~B() {
      std::cout << "~b " << std::endl;
    }
};

class C : public B {
  public:
    C(int a) : B(a) {
      std::cout << "c " << a << std::endl;
    }

    void p() override {
      std::cout << "sasa" << std::endl;
    }

    ~C() {
      std::cout << "~c " << std::endl;
    }
};

namespace utils {

  void classInheritance() {
    auto v = new C(4);

    // v->p();
    if (auto a = static_cast<B*>(v)) a->p();

    delete v;
  }

}
