//
//  Road.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/12/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Road_hpp
#define Road_hpp

#include <stdio.h>
#include <vector>

#include "Color.hpp"
#include "Rectangle.hpp"
#include "Line.hpp"

class Road: public Shape {
private:
    int length;
    int width;
    Point p1;
    Point p2;
    Shapes shapes;
    Line * middleLine;
    Rectangle * rect;
public:
    Road(Point _p1, Point _p2);
    ~Road();
    
    void draw();
    void update() {};
    bool contains(int x, int y);
    
    void update(Point _p1, Point _p2);
};

#endif /* Road_hpp */
