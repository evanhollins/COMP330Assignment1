//
//  Helicopter.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/20/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Helicopter.hpp"

Helicopter::Helicopter(int _x, int _y, int _size) {
    setX(_x);
    setY(_y);
    setSize(_size);
    bodyColor = new Color(1.0, 0.0, 0.0, 0.0);
}

void Helicopter::draw() {
    glColor3f(bodyColor->getR(), bodyColor->getG(), bodyColor->getB());
    glBegin(GL_POLYGON);
    glVertex2i(x+size/2, y+size/2);
    glVertex2i(x-size/2, y+size/2);
    glVertex2i(x-size/2, y-size/2);
    glVertex2i(x+size/2, y-size/2);
    glEnd();
}

int Helicopter::getX() {
    return x;
}

int Helicopter::getY() {
    return y;
}

int Helicopter::getSize() {
    return size;
}

int Helicopter::getAngle() {
    return angle;
}

void Helicopter::setX(int _x) {
    x = _x;
}

void Helicopter::setY(int _y) {
    y = _y;
}

void Helicopter::setSize(int _size) {
    size = _size;
}

void Helicopter::setAngle(int _angle) {
    angle = _angle;
}
