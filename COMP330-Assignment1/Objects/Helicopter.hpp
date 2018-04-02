//
//  Helicopter.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/20/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Helicopter_hpp
#define Helicopter_hpp

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <GLUT/GLUT.h>
using namespace std;

#include "Shape.hpp"
#include "Color.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Propeller.hpp"

class Helicopter {
private:
    int x;
    int y;
    int angle;
    int size;
    vector<Shape *> shapes;
    Propellor * propellor;
    Color * bodyColor;
    Color * propColor;
    
public:
    Helicopter(int _x, int _y, int _size);
    ~Helicopter();
    void draw();
    void update();
    int getX();
    int getY();
    int getSize();
    int getAngle();
    void setX(int _x);
    void setY(int _y);
    void setSize(int _size);
    void setAngle(int _angle);
};

#endif
