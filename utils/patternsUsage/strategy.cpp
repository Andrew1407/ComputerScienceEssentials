#include "../utils.hpp"

#include <iostream>
#include <math.h>

class ShapeStrategy {
  public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
};

class Circle : public ShapeStrategy {
  public:
    Circle(float radius) : radius(radius) {}
    float area() override { return M_PI * powf(radius, 2); }
    float perimeter() override { return 2 * M_PI * radius; }

  private:
    float radius;
};

class Rect : public ShapeStrategy {
  public:
    Rect(float a, float b) : a(a), b(b) {}
    float area() override { return a * b; }
    float perimeter() override { return 2 * (a + b); }

  private:
    float a;
    float b;
};

class Square : public Rect {
  public:
    Square(float a) : Rect(a, a) {}
};

enum Shape {
  CIRCLE,
  RECT,
  SQUARE,
};

ShapeStrategy* makeShape(Shape label, float param1, float param2 = 0) {
  switch (label) {
    case Shape::CIRCLE:
      return new Circle(param1);
    case Shape::RECT:
      return new Rect(param1, param2);
    case Shape::SQUARE:
      return new Square(param1);
    default:
      return nullptr;
  }
}

namespace utils {
  void useStrategy() {
    std::pair<const char*, ShapeStrategy*> shapes[] = {
      { "circle", makeShape(Shape::CIRCLE, 1) },
      { "square", makeShape(Shape::SQUARE, 2) },
      { "rect", makeShape(Shape::RECT, 2, 3) },
    };

    for (auto &[label, strategy] : shapes) {
      std::cout << label << ": " << std::endl
        << "- area: " << strategy->area() << std::endl
        << "- perimeter: " << strategy->perimeter()
        << std::endl;
    }

    for (auto &shape : shapes) delete shape.second;
  }
}
