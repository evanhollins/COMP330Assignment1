//
//  Road.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/12/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Road.hpp"

Road::Road(Point _p1, Point _p2) {
    p1 = _p1;
    p2 = _p2;
    
    rect = new Rectangle(p1, p2, Color::ROAD);
    shapes.add(rect);
    middleLine = new Line(p1.x, p1.y - (p1.y - p2.y)/2,
                                 p1.x, p1.y - (p1.y - p2.y)/2,
                                 10, Color::WHITE);
    middleLine->dashed = true;
    middleLine->lineStippleMultiplier = 32;
    shapes.add(middleLine);
    
}

Road::~Road() {

}

void Road::draw() {
    shapes.draw();
}

bool Road::contains(int x, int y) {
    return shapes.contains(x, y);
}

void Road::update(Point _p1, Point _p2) {
    p1 = _p1;
    p2 = _p2;
    
    rect->p1.x = p1.x;
    rect->p2.x = p2.x;
    
    middleLine->p1.x = p1.x;
    middleLine->p2.x = p2.x;
}
