//
//  Helicopter.h
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/15/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <GLUT/GLUT.h>
using namespace std;

#include "Color.h"

class Helicopter {
private:
    int x;
    int y;
    int angle;
    int size;
    
public:
    Helicopter(int _x, int _y, int _size);
    void draw();
    int getX();
    int getY();
    int getSize();
    int getAngle();
    void setX(int _x);
    void setY(int _y);
    void setSize(int _size);
    void setAngle(int _angle);
};

Helicopter::Helicopter(int _x, int _y, int _size) {
    setX(_x);
    setY(_y);
    setSize(_size);
}

void Helicopter::draw() {
    cout << "Draw helicopter" << endl;
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
