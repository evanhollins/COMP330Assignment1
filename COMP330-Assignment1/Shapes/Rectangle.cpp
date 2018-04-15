//
//  Rectangle.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Rectangle.hpp"

Rectangle::Rectangle() {
    p1 = Point(0, 0);
    p2 = Point(0, 0);
    angle = 0;
    color = Color::CLEAR;
}

Rectangle::Rectangle(int _x, int _y, int _size_x, int _size_y, Color::Color _color) {
    p1.x = _x - _size_x/2;
    p1.y = _y - _size_y/2;
    p2.x = _x + _size_x/2;
    p2.y = _y + _size_y/2;
    color = _color;
    angle = 0;
}

Rectangle::Rectangle(Point _p, int _size_x, int _size_y, Color::Color _color) {
    p1.x = _p.x - _size_x/2;
    p1.y = _p.y - _size_y/2;
    p2.x = _p.x + _size_x/2;
    p2.y = _p.y + _size_y/2;
    color = _color;
    angle = 0;
}

Rectangle::Rectangle(Point _p1, Point _p2, Color::Color _color) {
    p1 = _p1;
    p2 = _p2;
    color = _color;
    angle = 0;
}

Rectangle::~Rectangle() {
    
}

void Rectangle::draw() {
    color.set();
    glPushMatrix();
    glRotatef(angle, 0, 0, 1);
    glBegin(GL_POLYGON);
    p1.vertex();
    glVertex2i(p1.x, p2.y);
    p2.vertex();
    glVertex2i(p2.x, p1.y);
    glEnd();
    glPopMatrix();
}

bool Rectangle::contains(int _x, int _y) {
    return inRange(_x, p1.x, p2.x) && inRange(_y, p1.y, p2.y);
}
