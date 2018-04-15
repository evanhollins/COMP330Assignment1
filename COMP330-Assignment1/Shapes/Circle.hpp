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
#include "Shape.hpp"
#include "MathUtil.hpp"

class Circle : public Shape {
protected:
    const float TWICEPI = 3.14159*2;
    
public:
    int radius;
    Color::Color color;
    int x;
    int y;
    
    int iterations = FULL_CIRCLE_DEG;
    virtual void draw() =0;
    void update() {};
    bool contains(int _x, int _y);
    
    int getRadius();
    void setRadius(int r);
};


class OpenCircle: public Circle {
public:
    OpenCircle(int _x, int _y, int _radius, Color::Color _color);
    void draw();
};

class ClosedCircle: public Circle {
public:
    ClosedCircle(int _x, int _y, int _radius, Color::Color _color);
    void draw();
};

#endif /* Circle_hpp */
