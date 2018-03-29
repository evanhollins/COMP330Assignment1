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
#include "Drawable.hpp"

class Rectangle: public Drawable {
public:
    int size_x;
    int size_y;
    int angle;
    int x;
    int y;
    Color * color;
    
    Rectangle(int _x, int _y, int _size_x, int _size_y, Color * _color);
    ~Rectangle();
    virtual void draw();
    void update() {};
};

#endif /* Rectangle_hpp */
