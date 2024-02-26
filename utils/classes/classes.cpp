#include "../utils.hpp"

#include <iostream>
#include <math.h>

class Vector3 {
  public:
    static void ones(Vector3& pointer);
    Vector3(float x, float y, float z);
    float magnitude();
    ~Vector3() {
      std::cout << "bobo" << std::endl;
    }

  private:
    float x;
    float y;
    float z;
};

void Vector3::ones(Vector3& pointer) {
  pointer = Vector3(1, 1, 1);
}

Vector3::Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

float Vector3::magnitude() {
  return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
}

namespace utils
{

  void classDynamic() {
    // Vector3 v;
    // Vector3::ones(v);
    // auto v = Vector3(1, 1, 1);

    Vector3** vs = new (std::nothrow) Vector3*[3];
    // Vector3* vs[] = {
    //   new Vector3(),
    //   new Vector3(1, 1, 1),
    //   new Vector3(3, 2, 3),
    // };
    vs[0] = new (std::nothrow) Vector3();
    vs[1] = new (std::nothrow) Vector3(1, 1, 1);
    vs[2] = new (std::nothrow) Vector3(3, 2, 3);

    for (int i = 0; i < 3; ++i) {
      std::cout << vs[i]->magnitude() << std::endl;
      delete vs[i];
    }
    
    delete[] vs;
  }

}

