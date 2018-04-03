//
//  WaterBar.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "WaterBar.hpp"

WaterBar::WaterBar(int _x, int _y, int _width, int _height, Color * _color) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    color = _color;
    filled = 0;
    
    shapes.push_back(new Rectangle(x, y, size, color));
}

WaterBar::~WaterBar() {
    delete color;
}

void WaterBar::draw() {
    for(int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
}
