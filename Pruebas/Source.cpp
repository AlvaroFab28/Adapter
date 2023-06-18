#include <iostream>
#include <cmath>

class RoundHole {
private:
    int radius;

public:
    RoundHole(int radius) {
        this->radius = radius;
    }

    int getRadius() {
        return radius;
    }

    bool fits(int radius) {
        return (radius <= this->radius);
    }
};

class RoundPeg {
private:
    int radius;

public:
    RoundPeg(int radius) {
        this->radius = radius;
    }

    int getRadius() {
        return radius;
    }
};

class SquarePeg {
private:
    int width;

public:
    SquarePeg(int width) {
        this->width = width;
    }

    int getWidth() {
        return width;
    }
};

class SquarePegAdapter {
private:
    SquarePeg peg;

public:
  
    SquarePegAdapter(SquarePeg _peg) {
        peg = _peg;
    }

    int getRadius() {
        int width = peg.getWidth();
        int radius = static_cast<int>(std::sqrt(static_cast<double>(width * width) / 2.0));
        return radius;
    }
};

class Triangle {
private:
    double base;
    double height;

public:
    Triangle() {
        this->base = 0.0;
        this->height = 0.0;
    }

    Triangle(double base, double height) {
        this->base = base;
        this->height = height;
    }

    double getBase() {
        return base;
    }

    double getHeight() {
        return height;
    }
};

class TriangleAdapter {
private:
    Triangle triangle;

public:
    TriangleAdapter(Triangle triangle) {
        this->triangle = triangle;
    }

    double getRadius() {
        double area = (triangle.getBase() * triangle.getHeight()) / 2.0;
        double radius = std::sqrt(area / 3.14159);
        return radius;
    }
};

int main() {
    RoundHole hole(5);
    RoundPeg peg(3);

    if (hole.fits(peg.getRadius())) {
        std::cout << "El peg redondo cabe en el agujero redondo." << std::endl;
    }
    else {
        std::cout << "El peg redondo no cabe en el agujero redondo." << std::endl;
    }

    SquarePeg squarePeg(4);
    SquarePegAdapter squarePegAdapter(squarePeg);

    if (hole.fits(squarePegAdapter.getRadius())) {
        std::cout << "El peg cuadrado adaptado cabe en el agujero redondo." << std::endl;
    }
    else {
        std::cout << "El peg cuadrado adaptado no cabe en el agujero redondo." << std::endl;
    }

    Triangle triangle(6, 4);
    TriangleAdapter triangleAdapter(triangle);

    if (hole.fits(triangleAdapter.getRadius())) {
        std::cout << "El triángulo adaptado cabe en el agujero redondo." << std::endl;
    }
    else {
        std::cout << "El triángulo adaptado no cabe en el agujero redondo." << std::endl;
    }

    return 0;
}
