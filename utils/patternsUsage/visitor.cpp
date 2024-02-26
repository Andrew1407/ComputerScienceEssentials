#include "../utils.hpp"

#include <iostream>
#include <math.h>

class Circle;
class Square;
class Rect;

class Visitor {
  public:
    virtual void visit(Circle* acceptable) = 0;
    virtual void visit(Square* acceptable) = 0;
    virtual void visit(Rect* acceptable) = 0;
};

class ShapeStrategy {
  public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
    virtual void accept(Visitor* visitor) = 0;
};

class Circle : public ShapeStrategy {
  public:
    Circle(float radius) : radius(radius) {}
    float area() override { return M_PI * powf(radius, 2); }
    float perimeter() override { return 2 * M_PI * radius; }
    void accept(Visitor* visitor) override { visitor->visit(this); }

  private:
    float radius;
};

class Rect : public ShapeStrategy {
  public:
    Rect(float a, float b) : a(a), b(b) {}
    float area() override { return a * b; }
    float perimeter() override { return 2 * (a + b); }
    void accept(Visitor* visitor) override { visitor->visit(this); }

  private:
    float a;
    float b;
};

class Square : public Rect {
  public:
    Square(float a) : Rect(a, a) {}
    void accept(Visitor* visitor) override { visitor->visit(this); }
};

class VolumeVisitor: public Visitor {
  public:
    VolumeVisitor(float height) : height(height) {}

    virtual void visit(Circle* acceptable) {
      float volume = acceptable->area() * height;
      std::cout << "Cylinder volume: " << volume << std::endl;
    }

    virtual void visit(Square* acceptable) {
      float volume = acceptable->area() * height;
      std::cout << "Square prism volume: " << volume << std::endl;
    }

    virtual void visit(Rect* acceptable) {
      float volume = acceptable->area() * height;
      std::cout << "Prism volume: " << volume << std::endl;
    }

    private:
      float height;
};

namespace utils {
  void useVisitor() {
    VolumeVisitor vv(5);

    Circle c(1);
    Rect r(2, 3);
    Square s(2);

    c.accept(&vv);
    r.accept(&vv);
    s.accept(&vv);
  }
}
