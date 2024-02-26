#include "../utils.hpp"

#include <iostream>
#include <math.h>

class Shape {
  public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
};

class Circle : public Shape {
  public:
    Circle(float radius);
    float area() override;
    float perimeter() override;

  private:
    float radius;
};

Circle::Circle(float radius) : radius(radius) {}

float Circle::area() {
  return M_PI * powf(radius, 2);
}

float Circle::perimeter() {
  return 2 * M_PI * radius;
}

class Rect : public Shape {
  public:
    Rect(float a, float b);
    float area() override;
    float perimeter() override;

  private:
    float a;
    float b;
};

Rect::Rect(float a, float b) : a(a), b(b) {}

float Rect::area() {
  return a * b;
}

float Rect::perimeter() {
  return 2 * (a + b);
}

class Square : public Rect {
  public:
    Square(float a);
};

Square::Square(float a) : Rect(a, a) {}

namespace utils {

  void classAbstract() {
    Circle c(1);
    Rect r(4, 4);
    Square s(3);

    Shape* sh = &r;
    std::cout << sh->area() << ' ' << sh->perimeter() << std::endl;
  }

}
