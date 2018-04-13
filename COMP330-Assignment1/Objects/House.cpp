//
//  House.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/13/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "House.hpp"

House::House(int x, int y, int size) {
    this->p.x = x;
    this->p.y = y;
    this->size = size;
    init();
}

House::House(Point p, int size) {
    this->p = p;
    this->size = size;
    init();
}

void House::init() {
    Point topRightCorner = Point(p.x + size/2, p.y + size/2);
    Point topLeftCorner = Point(p.x - size/2, p.y + size/2);
    Point bottomRightCorner = Point(p.x + size/2, p.y - size/2);
    Point bottomLeftBorner = Point(p.x - size/2, p.y - size/2);
    shapes.add(new Rectangle(p.x - size / 4, p.y - size/4, size, size, Color::SHADOW));
    shapes.add(new Triangle(p, topRightCorner, topLeftCorner, Color::ROOF_GREEN_LIGHT));
    shapes.add(new Triangle(p, topRightCorner, bottomRightCorner, Color::ROOF_GREEN));
    shapes.add(new Triangle(p, topLeftCorner, bottomLeftBorner, Color::ROOF_GREEN));
    shapes.add(new Triangle(p, bottomLeftBorner, bottomRightCorner, Color::ROOF_GREEN_DARK));
    
    burntDownShapes.add(new ClosedCircle(p.x, p.y, size, Color::BLACK));
}

House::~House() {
    
}

void House::draw() {
    if(burntDown) {
        burntDownShapes.draw();
    } else {
        shapes.draw();
    }
}

bool House::contains(int x, int y) {
    if(burntDown) {
        return burntDownShapes.contains(x, y);
    } else {
        return shapes.contains(x, y);
    }
}
