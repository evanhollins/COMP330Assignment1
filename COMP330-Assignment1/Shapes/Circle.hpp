//
//  Circle.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include <iostream>
#include <GLUT/GLUT.h>
#include <math.h>

#include "Color.hpp"
#include "Drawable.hpp"

class OpenCircle: public Drawable {
public:
    float radius;
    Color * color;
    int x;
    int y;
    const float DEG2RAD = 3.14159/180;
    const float TWICEPI = 3.14159*2;
    int iterations;
    
    OpenCircle(int _x, int _y, float _radius, Color * _color);
    ~OpenCircle();
    virtual void draw();
    void update() {};
};

class ClosedCircle: public Drawable {
public:
    float radius;
    Color * color;
    int x;
    int y;
    const float DEG2RAD = 3.14159/180;
    const float TWICEPI = 3.14159*2;
    int iterations;
    
    ClosedCircle(int _x, int _y, float _radius, Color * _color);
    ~ClosedCircle();
    virtual void draw();
};

#endif /* Circle_hpp */
