//
//  Line.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/4/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>

#include "Shape.hpp"
#include "Point.hpp"
#include "Color.hpp"

class Line: public Shape {
public:
    Point * p1;
    Point * p2;
    bool dashed;
    Color * color;
    int stroke;
    Line(int _x1, int _y1, int _x2, int _y2, int _stroke, Color * _color);
    Line(Point * _p1, Point * _p2, int _stroke, Color * color);
    ~Line();
    void update() {};
    void draw();
    bool contains(int _x, int _y) { return false; };
};

#endif /* Line_hpp */
