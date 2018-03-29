//
//  Circle.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Circle.hpp"

OpenCircle::OpenCircle(int _x, int _y, float _radius, Color *  _color) {
    x = _x;
    y = _y;
    radius = _radius;
    color = _color;
    iterations = 360;
}

OpenCircle::~OpenCircle() {
    delete color;
}

void OpenCircle::draw() {
    color->set();
    glPushMatrix();
    glTranslatef(x, y, 0);
    glBegin(GL_LINE_LOOP);
    
    for (int i=0; i < iterations; i++)
    {
        float degInRad = i*DEG2RAD;
        glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
    }
    
    glEnd();
    glPopMatrix();
}

ClosedCircle::ClosedCircle(int _x, int _y, float _radius, Color *  _color) {
    x = _x;
    y = _y;
    radius = _radius;
    color = _color;
    iterations = 360;
}

ClosedCircle::~ClosedCircle() {
    delete color;
}

void ClosedCircle::draw() {
    color->set();
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
