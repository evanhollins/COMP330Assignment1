//
//  Trapazoid.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/17/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Trapazoid_hpp
#define Trapazoid_hpp

#include <stdio.h>
#include <iostream>

#include "Color.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include "MathUtil.hpp"

class Trapazoid: public Shape {
public:
    int angle;
    Point p1;
    Point p2;
    Point p3;
    Point p4;
    Color::Color color;
    
    Trapazoid();
    Trapazoid(Point p, int _size_x, int _size_y, int _size_y2,  Color::Color _color);
    ~Trapazoid();
    void draw();
    void update() {};
    bool contains(int, int);
};

#endif /* Trapazoid_hpp */
