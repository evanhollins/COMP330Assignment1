//
//  Rectangle.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

#include "Color.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include "MathUtil.hpp"

class Rectangle: public Shape {
public:
    int angle;
    Point p1;
    Point p2;
    Color::Color color;
    
    Rectangle();
    Rectangle(int _x, int _y, int _size_x, int _size_y, Color::Color _color);
    Rectangle(Point p, int _size_x, int _size_y, Color::Color _color);
    Rectangle(Point p1, Point p2, Color::Color _color);
    ~Rectangle();
    void draw();
    void update() {};
    bool contains(int, int);
};

#endif /* Rectangle_hpp */
