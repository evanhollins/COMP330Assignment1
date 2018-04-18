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

#define NUMBER_OF_PROPELLORS 3
#define PROPELLOR_WIDTH 12
#define PROPELLOR_SPEED 5

class Propellor: public Shape {
public:
    int radius;
    int angle;
    bool spinning;
    Color::Color color;
    ClosedCircle * propBackground;
    const float TWICEPI = 3.14159 * 2;
    
    Propellor(int _x, int _y, int _radius);
    ~Propellor();
    void draw();
    void update();
    bool contains(int _x, int _y) {return false;}
    void spin();
    void stop();
};


#endif /* Propeller_hpp */
