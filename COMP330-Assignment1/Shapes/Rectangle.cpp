//
//  Rectangle.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Rectangle.hpp"

Rectangle::Rectangle(int _x, int _y, int _size_x, int _size_y, Color * _color) {
    x = _x;
    y = _y;
    size_x = _size_x;
    size_y = _size_y;
    color = _color;
}

Rectangle::~Rectangle() {
    delete color;
}

void Rectangle::draw() {
    color->set();
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(angle, 0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(size_x/2, size_y/2);
    glVertex2i(-size_x/2, size_y/2);
    glVertex2i(-size_x/2, -size_y/2);
    glVertex2i(size_x/2, -size_y/2);
    glEnd();
    glPopMatrix();
}
