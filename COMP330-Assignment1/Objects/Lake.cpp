//
//  Lake.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Lake.hpp"

Lake::Lake(int _x, int _y, int _size, Color * _color) {
    x = _x;
    y = _y;
    size = _size;
    color = _color;
    
    shapes.push_back(new ClosedCircle(x, y, size, color));
}

Lake::~Lake() {
    delete color;
}

void Lake::draw() {
    for(int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
}

bool Lake::contains(int _x, int _y) {
    for(int i = 0; i < shapes.size(); i++) {
        if(shapes[i]->contains(_x, _y)) {
            return true;
        }
    }
    return false;
}
