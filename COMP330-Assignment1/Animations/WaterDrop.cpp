//
//  WaterDrop.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/15/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "WaterDrop.hpp"

WaterDrop::WaterDrop(Point _p) {
    p = _p;
    duration = DEFUALT_DURATION;
    init();
}

WaterDrop::WaterDrop(Point _p, int _duration) {
    p = _p;
    duration = _duration;
    init();
}

WaterDrop::WaterDrop(int x, int y) {
    p.x = x;
    p.y = y;
    duration = DEFUALT_DURATION;
    init();
}

WaterDrop::WaterDrop(int x, int y, int _duration) {
    p.x = x;
    p.y = y;
    duration = _duration;
    init();
}

WaterDrop::~WaterDrop() {
    delete water;
}

void WaterDrop::init() {
    currentColor = Color::WATER;
    running = false;
    water = new ClosedCircle(p.x, p.y, WATER_START_SIZE, currentColor);
}

void WaterDrop::start() {
    cycles = 0;
    running = true;
}

void WaterDrop::setLocation(Point p) {
    this->p = p;
    water->x = p.x;
    water->y = p.y;
}

void WaterDrop::update() {
    if(running) {
        if(cycles < duration) {
            water->radius = WATER_END_SIZE + (WATER_START_SIZE - WATER_END_SIZE) * (duration - cycles)/duration;
            currentColor.a = WATER_END_ALPHA + (WATER_START_ALPHA - WATER_END_ALPHA) * (duration - cycles)/duration;
            water->color = currentColor;
            cycles++;
        } else {
            running = false;
        }
    }
}

void WaterDrop::draw() {
    if(running) {
        water->draw();
    }
}

bool WaterDrop::contains(int x, int y) {
    return water->contains(x, y);
}
