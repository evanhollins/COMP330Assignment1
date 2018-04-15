//
//  Road.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/12/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Road.hpp"

Road::Road(Point _p1, int _length, int _width) {
    p = _p1;
    
    length = _length;
    width = _width;
    
    shapes.add(new Rectangle(p, length, width, Color::ROAD));
    Line * middleLine = new Line(p.x - length/2, p.y,
                                 p.x + length/2, p.y,
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
