//
//  Circle.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Circle.hpp"

int Circle::getRadius() {
    return radius;
}

void Circle::setRadius(int r) {
    radius = r;
}

OpenCircle::OpenCircle(int _x, int _y, int _radius, Color::Color _color) {
    x = _x;
    y = _y;
    radius = _radius;
    color = _color;
}

ClosedCircle::ClosedCircle(int _x, int _y, int _radius, Color::Color _color) {
    x = _x;
    y = _y;
    radius = _radius;
    color = _color;
}

bool Circle::contains(int _x, int _y) {
    return sqrt(pow((x - _x),2) + pow((y - _y),2)) <= radius;
}

void OpenCircle::draw() {
    color.set();
    glPushMatrix();
    glTranslatef(x, y, 0);
    glBegin(GL_LINE_LOOP);
    for (int i=0; i < iterations; i++)
    {
        float degInRad = rad(i);
        glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
    }
    glEnd();
    glPopMatrix();
}

void ClosedCircle::draw() {
    color.set();
    glPushMatrix();
    glTranslatef(x, y, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0); // center of circle
    for(int i = 0; i <= iterations;i++) {
        glVertex2f(
                   (radius * cos(i *  TWICEPI / iterations)),
                   (radius * sin(i * TWICEPI / iterations))
                   );
    }
    glEnd();
    glPopMatrix();
}
