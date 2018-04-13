//
//  Line.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/4/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Line.hpp"

Line::Line() {
    p1 = Point(0, 0);
    p2 = Point(0, 0);
    dashed = false;
    color = Color::CLEAR;
}

Line::~Line() {
}

void Line::draw() {
    glPushAttrib(GL_ENABLE_BIT);
    glLineWidth(stroke);
    color.set();
    if(dashed) {
        glLineStipple(lineStippleMultiplier, lineStipplePattern);
        glEnable(GL_LINE_STIPPLE);
        glBegin(GL_LINE_STRIP);
    } else {
        glBegin(GL_LINES);
    }
    p1.vertex();
    p2.vertex();
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glPopAttrib();
}
