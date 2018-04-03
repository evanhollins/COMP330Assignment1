//
//  WaterBar.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef WaterBar_hpp
#define WaterBar_hpp

#include <stdio.h>
#include <vector>

#include "Color.hpp"
#include "Shape.hpp"
#include "Rectangle.hpp"

class WaterBar: public Shape {
private:
    vector<Shape *> shapes;
    float filled;
public:
    int x;
    int y;
    int height;
    int width;
    Color * color;
    WaterBar(int _x, int _y, int _width, int _height, Color * _color);
    ~WaterBar();
    void draw();
    void update() {};
    bool contains() { return false; };
};
#endif /* WaterBar_hpp */
