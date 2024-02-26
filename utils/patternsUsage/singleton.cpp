#include "../utils.hpp"

#include <iostream>

class Singleton {
  public:
    static Singleton& getInstance();
    Singleton(Singleton const&) = delete;
    void operator=(Singleton const&) = delete;
    int a = 4;
  private:
    Singleton() = default;
    static Singleton* instance;
};

Singleton* Singleton::instance = nullptr;

Singleton& Singleton::getInstance() {
  // static Singleton instance;
  if (!instance) instance = new Singleton();
  return *instance;
}

namespace utils {
  void useSingleton() {
    Singleton& s = Singleton::getInstance();
    Singleton& s1 = Singleton::getInstance();
    s1.a = 90;
    std::cout << s.a << std::endl;
  }
}
