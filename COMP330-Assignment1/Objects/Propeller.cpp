//
//  Propeller.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Propeller.hpp"

Propellor::Propellor(int _x, int _y, int _radius) {
    x = _x;
    y = _y;
    radius = _radius;
    angle = 0;
    spinning = true;
    color = Color::GRAY;
    Color::Color backgroundColor = Color::GRAY;
    backgroundColor.a = 0.2;
    propBackground = new ClosedCircle(x, y, radius, backgroundColor);
}
Propellor::~Propellor() {
    delete propBackground;
}

void Propellor::update() {
    if(spinning) {
        angle = (angle + 5) % 360;
    }
}

void Propellor::draw() {
    propBackground->draw();
    color.set();
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(angle, 0, 0, 1);
    for(int i = 0; i < 3; i++) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0, 0); // center of circle
        for(int j = 0; j < 12; j++) {
            glVertex2f(
                       (radius * cos((j + (120 * i)) * TWICEPI / FULL_CIRCLE_DEG)),
                       (radius * sin((j + (120 * i)) * TWICEPI / FULL_CIRCLE_DEG))
                       );
        }
        glEnd();
    }
    
    glPopMatrix();
    
}

void Propellor::spin() {
    spinning = true;
}

void Propellor::stop() {
    spinning = false;
}
