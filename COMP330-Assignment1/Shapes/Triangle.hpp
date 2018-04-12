//
//  Triangle.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/12/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>

#include "Point.hpp"
#include "Color.hpp"
#include "Shape.hpp"

class Triangle: public Shape {
public:
    Point p0;
    Point p1;
    Point p2;
    Color::Color color;
    float area;
    
    Triangle(Point _p0, Point _p1, Point _p2, Color::Color _color): p0(_p0), p1(_p1), p2(_p2), color(_color) {
        area = 0.5 *(-_p1.y*_p2.x + _p0.y*(-_p1.x + _p2.x) + _p0.x*(_p1.y - _p2.y) + _p1.x*_p2.y);
    } ;
    ~Triangle() {};
    
    void draw();
    void update() {};
    bool contains(int x, int y);
};

#endif /* Triangle_hpp */
