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
public:
    Point p1;
    int length;
    int width;
    vector<Shape *> shapes;
    Road(Point _p1, int _length, int _width);
    ~Road();
    
    void draw();
    void update() {};
    bool contains(int x, int y);
};

#endif /* Road_hpp */
