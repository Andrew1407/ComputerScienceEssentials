#include "../utils.hpp"

#include <iostream>

struct Vector2 {
  public:
    Vector2(float x = 0, float y = 0): x(x), y(y) {}
    float x = 0;
    float y = 0;

    Vector2& operator++ () {
      ++x;
      ++y;
      return *this;
    }

    Vector2 operator++ (int) {
      Vector2 prev = *this; 
      ++x;
      ++y;
      return prev;
    }

    Vector2 operator- (Vector2& other) {
      return Vector2(this->x - other.x, this->y - other.y);
    }

    Vector2* operator= (Vector2& other) {
      this->x = other.x;
      this->y = other.y;
      return this;
    }

    Vector2* operator= (Vector2 other) {
      this->x = other.x;
      this->y = other.y;
      return this;
    }

    // std::string operator* () {
    //   return std::to_string(x) + ' ' + std::to_string(y);
    // }

    std::string operator* ();
};

std::string Vector2::operator* () {
  return std::to_string(x) + ' ' + std::to_string(y);
}

Vector2 operator+ (Vector2& a, Vector2& b) {
  return Vector2(a.x + b.y, a.y + b.y);
}

Vector2 operator+ (Vector2& a, int b) {
  return Vector2(a.x + b, a.y + b);
}

namespace utils {

  void operatorsOverloading() {
    Vector2 v(1, 1);
    Vector2 v2(-1, 2);
    v = Vector2(5, 5);

    v = v + 3;

    // std:: cout << *v << std::endl;
    std:: cout << *(v - v2) << std::endl;
    std:: cout << *v << std::endl;
  }

}
