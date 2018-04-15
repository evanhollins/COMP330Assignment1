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

#include "MathUtil.hpp"
#include "Shape.hpp"
#include "Color.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Line.hpp"
#include "Propeller.hpp"
#include "WaterDrop.hpp"

#define HELICOPTER_MAX_SPEED 2
#define HELICOPTER_MAX_ANGLE_CHANGE 3
#define HELICOPTER_MAX_SCALE_CHANGE 0.01
#define HELICOPTER_DEADBAND 1

class Helicopter {
private:
    Point location;
    Point target;
    int angle;
    int targetAngle;
    int size;
    float scale;
    float targetScale;
    int speed;
    bool flying;
    vector<Shape *> shapes;
    Propellor * propellor;
    Line * path;
    Animations animations;
    
public:
    Helicopter(int _x, int _y, int _size);
    ~Helicopter();
    void draw();
    void update();
    int getX();
    int getY();
    int getTargetX();
    int getTargetY();
    int getTargetAngle();
    int getSize();
    int getAngle();
    float distanceTo(int _x, int _y);
    bool contains(int _x, int _y);
    void setX(int _x);
    void setY(int _y);
    void setTargetX(int _x);
    void setTargetY(int _y);
    void setSize(int _size);
    void setAngle(int _angle);
    void setTargetAngle(int _angle);
    void setSpeed(int _speed);
    int getSpeed();
    void land();
    void takeoff();
    void dropWater();
};

#endif
