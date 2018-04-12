//
//  Triangle.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/12/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Triangle.hpp"

void Triangle::draw() {
    glPushMatrix();
    color.set();
    glBegin(GL_POLYGON);
    p0.vertex();
    p1.vertex();
    p2.vertex();
    glEnd();
    glPopMatrix();
}


// Using barycentric coordinates
bool Triangle::contains(int x, int y) {
    float s = 1/(2*area)*(p0.y*p2.x - p0.x*p2.y + (p2.y - p0.y)*x + (p0.x - p2.x)*y);
    float t = 1/(2*area)*(p0.x*p1.y - p0.y*p1.x + (p0.y - p1.y)*x + (p1.x - p0.x)*y);
    
    return s > 0 && t > 0 && 1-s-t > 0;
}
