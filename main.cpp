#include <iostream>
#include <memory>
#include <cmath>


class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};


class Circle : public Shape {

    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

class Rectangle : public Shape {
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};


class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& type, double a, double b = 0) {
        if (type == "circle") {
            return std::make_unique<Circle>(a);
        } else if (type == "square") {
            return std::make_unique<Square>(a);
        } else if (type == "rectangle") {
            return std::make_unique<Rectangle>(a, b);
        } else {
            return nullptr;
        }
    }
};

int main() {
    auto circle = ShapeFactory::createShape("circle", 89);
    auto square = ShapeFactory::createShape("square", 49);
    auto rectangle = ShapeFactory::createShape("rectangle", 4, 6);

    if (circle) std::cout << "Circle area: " << circle->area() << std::endl;
    if (square) std::cout << "Square area: " << square->area() << std::endl;
    if (rectangle) std::cout << "Rectangle area: " << rectangle->area() << std::endl;

    return 0;
}