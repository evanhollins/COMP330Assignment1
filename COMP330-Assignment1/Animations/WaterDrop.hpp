//
//  WaterDrop.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/15/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef WaterDrop_hpp
#define WaterDrop_hpp

#include <stdio.h>
#include <iostream>

#include "Shape.hpp"
#include "Point.hpp"
#include "Color.hpp"
#include "Circle.hpp"
#include "Animation.hpp"

#define DEFUALT_DURATION 60
#define WATER_START_SIZE 10
#define WATER_END_SIZE 50
#define WATER_START_ALPHA 1.0
#define WATER_END_ALPHA 0.2

class WaterDrop: public Animation {
    Point p;
    ClosedCircle * water;
    Color::Color currentColor;
public:
    WaterDrop(Point p, int duration);
    WaterDrop(Point p);
    WaterDrop(int x, int y, int duration);
    WaterDrop(int x, int y);
    ~WaterDrop();
    void init();
    
    void update();
    void draw();
    bool contains(int x, int y);
    
    void start();
    void setLocation(Point p);
};

#endif /* WaterDrop_hpp */
