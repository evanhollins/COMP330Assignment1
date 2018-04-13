//
//  Fire.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/12/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Fire.hpp"

Fire::Fire(int x, int y) {
    this->x = x;
    this->y = y;

    shapes.add(new ClosedCircle(x, y, FIRE_SIZE, Color::FIRE_RED));
    shapes.add(new Triangle(Point(x - FIRE_SIZE*0.87, y - FIRE_SIZE*0.5), Point(x + FIRE_SIZE*0.88, y - FIRE_SIZE*0.5), Point(x, y - FIRE_SIZE*2.2), Color::FIRE_RED));
    shapes.add(new ClosedCircle(x, y, FIRE_SIZE - 5, Color::FIRE_ORANGE));
    shapes.add(new Triangle(Point(x - (FIRE_SIZE-5)*0.87, y - (FIRE_SIZE-5)*0.5), Point(x + (FIRE_SIZE-5)*0.88, y - (FIRE_SIZE-5)*0.5), Point(x, y - (FIRE_SIZE-5)*2.2), Color::FIRE_ORANGE));
    shapes.add(new ClosedCircle(x, y, FIRE_SIZE - 10, Color::FIRE_YELLOW));
    shapes.add(new Triangle(Point(x - (FIRE_SIZE-10)*0.87, y - (FIRE_SIZE-10)*0.5), Point(x + (FIRE_SIZE-10)*0.88, y - (FIRE_SIZE-10)*0.5), Point(x, y - (FIRE_SIZE-10)*2.2), Color::FIRE_YELLOW));
}

Fire::~Fire() {
}

void Fire::draw() {
    shapes.draw();
}

bool Fire::contains(int _x, int _y) {
    return shapes.contains(_x, _y);
}
