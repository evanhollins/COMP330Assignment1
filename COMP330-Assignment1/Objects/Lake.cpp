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
}

Lake::~Lake() {
}

void Lake::draw() {
    shapes.draw();
}

bool Lake::contains(int _x, int _y) {
    return shapes.contains(_x, _y);
}
