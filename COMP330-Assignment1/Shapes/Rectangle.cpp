//
//  Rectangle.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Rectangle.hpp"

Rectangle::Rectangle() {
    p = Point(0, 0);
    size_x = 0;
    size_y = 0;
    angle = 0;
    color = Color::CLEAR;
}

Rectangle::Rectangle(int _x, int _y, int _size_x, int _size_y, Color::Color _color) {
    p.x = _x;
    p.y = _y;
    size_x = _size_x;
    size_y = _size_y;
    color = _color;
    angle = 0;
}

Rectangle::Rectangle(Point _p, int _size_x, int _size_y, Color::Color _color) {
    p = _p;
    size_x = _size_x;
    size_y = _size_y;
    color = _color;
    angle = 0;
}

Rectangle::~Rectangle() {
    
}

void Rectangle::draw() {
    color.set();
    glPushMatrix();
    p.translate();
    glRotatef(angle, 0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(size_x/2, size_y/2);
    glVertex2i(-size_x/2, size_y/2);
    glVertex2i(-size_x/2, -size_y/2);
    glVertex2i(size_x/2, -size_y/2);
    glEnd();
    glPopMatrix();
}

bool Rectangle::contains(int _x, int _y) {
    return abs(p.x - _x) <= size_x/2 && abs(p.y - _y) <= size_y/2;
}
