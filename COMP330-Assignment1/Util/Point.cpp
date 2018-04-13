//
//  Point.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/4/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Point.hpp"

float Point::distanceTo(int _x, int _y) {
    return sqrt(pow(x - _x, 2) + pow(y - _y, 2));
}

float Point::distanceTo(Point b) {
    return distanceTo(b.x, b.y);
}

void Point::vertex() {
    glVertex2i(x, y);
}

void Point::translate() {
    glTranslatef(x, y, 0);
}
