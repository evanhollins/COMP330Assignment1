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

    shapes.push_back(new ClosedCircle(x, y, FIRE_SIZE, Color::FIRE_RED));
    shapes.push_back(new Triangle(Point(x - FIRE_SIZE*0.87, y - FIRE_SIZE*0.5), Point(x + FIRE_SIZE*0.88, y - FIRE_SIZE*0.5), Point(x, y - FIRE_SIZE*2.2), Color::FIRE_RED));
    shapes.push_back(new ClosedCircle(x, y, FIRE_SIZE - 5, Color::FIRE_ORANGE));
    shapes.push_back(new Triangle(Point(x - (FIRE_SIZE-5)*0.87, y - (FIRE_SIZE-5)*0.5), Point(x + (FIRE_SIZE-5)*0.88, y - (FIRE_SIZE-5)*0.5), Point(x, y - (FIRE_SIZE-5)*2.2), Color::FIRE_ORANGE));
    shapes.push_back(new ClosedCircle(x, y, FIRE_SIZE - 10, Color::FIRE_YELLOW));
    shapes.push_back(new Triangle(Point(x - (FIRE_SIZE-10)*0.87, y - (FIRE_SIZE-10)*0.5), Point(x + (FIRE_SIZE-10)*0.88, y - (FIRE_SIZE-10)*0.5), Point(x, y - (FIRE_SIZE-10)*2.2), Color::FIRE_YELLOW));
}

Fire::~Fire() {
    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
}

void Fire::draw() {
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
}

bool Fire::contains(int _x, int _y) {
    for (int i = 0; i < shapes.size(); i++) {
        if (shapes[i]->contains(_x, _y)) {
            return true;
        }
    }
    return false;
}
