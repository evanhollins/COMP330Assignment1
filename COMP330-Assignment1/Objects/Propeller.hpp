//
//  Propeller.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Propeller_hpp
#define Propeller_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

#include "Shape.hpp"
#include "Color.hpp"
#include "Circle.hpp"

class Propellor: public Shape {
public:
    int x;
    int y;
    int radius;
    int angle;
    Color * color;
    Color * backgroundColor;
    ClosedCircle * propBackground;
    const float TWICEPI = 3.14159 * 2;
    
    Propellor(int _x, int _y, int _radius, Color * _color);
    ~Propellor();
    virtual void draw();
    void update();
};


#endif /* Propeller_hpp */
