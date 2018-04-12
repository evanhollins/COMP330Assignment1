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

class Rectangle: public Shape {
public:
    int size_x;
    int size_y;
    int angle;
    int x;
    int y;
    Color::Color color;
    
    Rectangle(int _x, int _y, int _size_x, int _size_y, Color::Color _color): x(_x), y(_y), size_x(_size_x), size_y(_size_y), color(_color) {angle = 0;};
    ~Rectangle();
    void draw();
    void update() {};
    bool contains(int, int);
};

#endif /* Rectangle_hpp */
