//
//  Line.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/4/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Line.hpp"

Line::Line(int _x1, int _y1, int _x2, int _y2, int _stroke, Color * _color) {
    p1 = new Point(_x1, _y1);
    p2 = new Point(_x2, _y2);
    stroke = _stroke;
    color = _color;
    dashed = false;
}

Line::Line(Point * _p1, Point * _p2, int _stroke, Color * _color) {
    p1 = _p1;
    p2 = _p2;
    stroke = _stroke;
    color = _color;
    dashed = false;
}

Line::~Line() {
    delete color;
    delete p1;
    delete p2;
}

void Line::draw() {
    glPushAttrib(GL_ENABLE_BIT);
    glLineWidth(stroke);
    color->set();
    if(dashed) {
        glLineStipple(4, 0xAAAA);
        glEnable(GL_LINE_STIPPLE);
        glBegin(GL_LINE_STRIP);
    } else {
        glBegin(GL_LINES);
    }
    p1->vertex();
    p2->vertex();
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glPopAttrib();
}
