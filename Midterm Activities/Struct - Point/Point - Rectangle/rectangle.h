// TODO create struct Rectangle here, with the methods area() and perimeter()
#include <iostream>
#include <cstdlib>
#include "point.h"

struct Rectangle {
    Point point1;
    Point point2;

    int perimeter() {
        int length, width;
        width = abs(point1.x - point2.x);
        length = abs(point1.y - point2.y);
        return (2*length + 2*width);
    }

    int area() {
        int length, width;
        width = abs(point1.x - point2.x);
        length = abs(point1.y - point2.y);
        return (length * width);
    }
};