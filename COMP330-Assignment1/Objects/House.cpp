//
//  House.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/13/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "House.hpp"

House::House(int x, int y, int size) {
    p = Point(x, y);
    this->size = size;
    init();
}

House::House(Point p, int size) {
    this->p = p;
    this->size = size;
    init();
}

void House::init() {
    switch (rand() % 3) {
        case 0:
            roofColorLight = Color::ROOF_RED_LIGHT;
            roofColor = Color::ROOF_RED;
            roofColorDark = Color::ROOF_RED_DARK;
            break;
        case 1:
            roofColorLight = Color::ROOF_TAN_LIGHT;
            roofColor = Color::ROOF_TAN;
            roofColorDark = Color::ROOF_TAN_DARK;
            break;
        case 2:
            roofColorLight = Color::ROOF_BRICK_LIGHT;
            roofColor = Color::ROOF_BRICK;
            roofColorDark = Color::ROOF_BRICK_DARK;
            break;
    }
    
    
    
    Point topRightCorner = Point(p.x + size/2, p.y + size/2);
    Point topLeftCorner = Point(p.x - size/2, p.y + size/2);
    Point bottomRightCorner = Point(p.x + size/2, p.y - size/2);
    Point bottomLeftBorner = Point(p.x - size/2, p.y - size/2);
    shapes.add(new Rectangle(p.x - size/8, p.y - size/8, size, size, Color::SHADOW));
    shapes.add(new Triangle(p, topRightCorner, topLeftCorner, roofColorLight));
    shapes.add(new Triangle(p, topRightCorner, bottomRightCorner, roofColor));
    shapes.add(new Triangle(p, topLeftCorner, bottomLeftBorner, roofColor));
    shapes.add(new Triangle(p, bottomLeftBorner, bottomRightCorner, roofColorDark));

    potentialFire[0] = new Fire(p.x + size/4, p.y + size/4);
    potentialFire[1] = new Fire(p.x + size/4, p.y - size/4);
    potentialFire[2] = new Fire(p.x - size/4, p.y + size/4);
    potentialFire[3] = new Fire(p.x - size/4, p.y - size/4);
    std::random_shuffle(&potentialFire[0], &potentialFire[3]);
    
    Color::Color ashes = Color::BLACK;
    ashes.a = 0.6;
    burntDownShapes.add(new ClosedCircle(p.x, p.y, size/2, ashes));
    
    setFire();
}

House::~House() {
    
}

void House::update() {
    if(onFire > 0) {
        onFireCycles++;
    }
    if(onFireCycles > HOUSE_MAX_FIRE_CYCLES) {
        if(fire.size() == HOUSE_MAX_FIRE) {
            burntDown = true;
            onFire = false;
        } else {
            fire.push_back(potentialFire[fire.size()]);
        }
        onFireCycles = 0;
    }
}

void House::draw() {
    if(burntDown) {
        burntDownShapes.draw();
    } else {
        shapes.draw();
        for (int i = 0; i < fire.size(); i++) {
            fire[i]->draw();
        }
    }
}

bool House::contains(int x, int y) {
    if(burntDown) {
        return burntDownShapes.contains(x, y);
    } else {
        return shapes.contains(x, y);
    }
}

void House::setFire() {
    onFire = true;
    fire.push_back(potentialFire[0]);
}

void House::water() {
    onFire = false;
    std::for_each(fire.begin(), fire.end(), [](Fire * f) {
        f->douse();
    });
    onFireCycles = 0;
}
