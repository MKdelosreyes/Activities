#include <iostream>
#include "rectangle.h"
using namespace std;

int main() {
    Rectangle rect;
    cout << "Enter x of rectangle point 1: ";
    // TODO store the x-coord of rectangle's first point here.
    cin >> rect.point1.x;
    cout << "Enter y of rectangle point 1: ";
    // TODO store the y-coord of rectangle's first point here.
    cin >> rect.point1.y;
    cout << "Enter x of rectangle point 2: ";
    // TODO store the x-coord of rectangle's second point here.
    cin >> rect.point2.x;
    cout << "Enter y of rectangle point 2: ";
    // TODO store the y-coord of rectangle's second point here.
    cin >> rect.point2.y;

    cout << endl << "Perimeter of the rectangle: " << rect.perimeter();
    cout << endl << "Area of the rectangle: " << rect.area() << endl;
    return 0;
}