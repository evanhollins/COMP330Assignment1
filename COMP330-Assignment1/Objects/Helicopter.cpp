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
    setAngle(0);
    bodyColor = new Color(0.2, 0.2, 0.2, 1.0);
    propColor = new Color(0.5, 0.5, 0.5, 1.0);
    // Body
    shapes.push_back(new ClosedCircle(0, 0, size/2, bodyColor));
    shapes.push_back(new Rectangle(size/2, 0, size, size/4, bodyColor));
    shapes.push_back(new Rectangle(size, 0, size / 8, size / 2, bodyColor));
    // Prop
    propellor = new Propellor(0, 0, size, propColor);
}

Helicopter::~Helicopter() {
    delete bodyColor;
    delete propColor;
    for(int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
}

void Helicopter::draw() {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(angle, 0, 0, 1);
    for(int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
    glPopMatrix();
    glPushMatrix();
    glTranslatef(x, y, 0);
    propellor->draw();
    glPopMatrix();
}

void Helicopter::update() {
    for(int i = 0; i < shapes.size(); i++) {
        shapes[i]->update();
    }
    propellor->update();
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
    angle = (_angle + 180) % 360;
}

