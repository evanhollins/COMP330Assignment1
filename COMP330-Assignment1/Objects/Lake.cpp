//
//  Lake.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Lake.hpp"

Lake::Lake(int _x, int _y, int _size) {
    x = _x;
    y = _y;
    size = _size;
    
    shapes.add(new ClosedCircle(x, y, size, Color::WATER));
    Color::Color darkerWater = Color::WATER;
    darkerWater.r -= 0.1;
    darkerWater.g -= 0.1;
    darkerWater.b -= 0.1;
    shapes.add(new ClosedCircle(x, y, size*0.6, darkerWater));
    Color::Color darkestWater = darkerWater;
    darkestWater.r -= 0.1;
    darkestWater.g -= 0.1;
    darkestWater.b -= 0.1;
    shapes.add(new ClosedCircle(x, y, size*0.4, darkestWater));
}

Lake::~Lake() {
}

void Lake::draw() {
    shapes.draw();
}

bool Lake::contains(int _x, int _y) {
    return shapes.contains(_x, _y);
}
