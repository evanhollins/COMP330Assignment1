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
    float radius;
    Color color;
    int x;
    int y;
    
    int iterations;
    Circle(int _x, int _y, float _radius, Color _color):
        x(_x), y(_y), radius(_radius), color(_color) {
        iterations = FULL_CIRCLE_DEG;
    };
    ~Circle();
    virtual void draw() =0;
    void update() {};
    bool contains(int _x, int _y);
};


class OpenCircle: public Circle {
public:
    OpenCircle(int _x, int _y, float _radius, Color _color):
        Circle(_x, _y, _radius, _color) {};
    ~OpenCircle() = default;
    virtual void draw();
};

class ClosedCircle: public Circle {
public:
    ClosedCircle(int _x, int _y, float _radius, Color _color):
        Circle(_x, _y, _radius, _color) {};
    ~ClosedCircle() = default;
    virtual void draw();
};

#endif /* Circle_hpp */
