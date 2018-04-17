//
//  Lake.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Lake.hpp"

Lake::Lake(int _x, int _y, int _size) {
    setPoint(_x, _y);
    size = _size;
    
    shapes.add(new ClosedCircle(p.x, p.y, size, Color::WATER));
    Point smallerLake = Point(p.x - 100, p.y + 20);
    shapes.add(new ClosedCircle(smallerLake.x, smallerLake.y, size - 30, Color::WATER));
    
    Trapazoid * bridge = new Trapazoid(p.between(smallerLake), p.distanceTo(smallerLake), (size - 30)*2, size*2, Color::WATER);
    bridge->angle = -11;
    
    shapes.add(bridge);
    
    Color::Color darkerWater = Color::WATER;
    darkerWater.r -= 0.1;
    darkerWater.g -= 0.1;
    darkerWater.b -= 0.1;
    shapes.add(new ClosedCircle(p.x + 5, p.y, size*0.8, darkerWater));
    Color::Color darkestWater = darkerWater;
    darkestWater.r -= 0.1;
    darkestWater.g -= 0.1;
    darkestWater.b -= 0.1;
    shapes.add(new ClosedCircle(p.x + 10, p.y, size*0.4, darkestWater));
    
    
    
    
}

Lake::~Lake() {
}

void Lake::draw() {
    shapes.draw();
}

bool Lake::contains(int _x, int _y) {
    return shapes.contains(_x, _y);
}
