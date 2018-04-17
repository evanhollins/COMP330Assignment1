//
//  Trapazoid.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/17/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Trapazoid.hpp"

Trapazoid::Trapazoid() {
    p1 = Point(0, 0);
    p2 = Point(0, 0);
    p3 = Point(0, 0);
    p4 = Point(0, 0);
    angle = 0;
    color = Color::CLEAR;
}

Trapazoid::Trapazoid(Point _p, int x, int y1, int y2, Color::Color _color) {
    p = _p;
    p1.x = -x/2;
    p1.y = y1/2;
    p2.x = -x/2;
    p2.y = -y1/2;
    p3.x = x/2;
    p3.y = -y2/2;
    p4.x = x/2;
    p4.y = y2/2;
    color = _color;
    angle = 0;
}

Trapazoid::~Trapazoid() {
    
}

void Trapazoid::draw() {
    color.set();
    glPushMatrix();
    p.translate();
    glRotatef(angle, 0, 0, 1);
    glBegin(GL_POLYGON);
    p1.vertex();
    p2.vertex();
    p3.vertex();
    p4.vertex();
    glEnd();
    glPopMatrix();
}

bool Trapazoid::contains(int _x, int _y) {
    return false;
}
