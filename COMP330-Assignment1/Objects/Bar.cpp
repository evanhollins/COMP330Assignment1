//
//  Bar.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Bar.hpp"

Bar::Bar(int _x, int _y, int _width, int _height, Color::Color _color) {
    setPoint(_x, _y);
    width = _width;
    height = _height;
    filled = BAR_MIN_FILLED;
    color = _color;
    
    background = new Rectangle(p.x, p.y, width, height, Color::BLACK);
    Point foregroundTopRight = Point(p.x + width/2 - PADDING, p.y + height/2 - PADDING);
    Point foregroundBottomLeft = Point(p.x + width/2 - getFilledBarX(), p.y - height/2 + PADDING);
    foreground = new Rectangle(foregroundTopRight, foregroundBottomLeft, color);
}

Bar::~Bar() {
}

void Bar::draw() {
    background->draw();
    foreground->draw();
}

float Bar::getFilledBarX() {
    return (width - PADDING) * filled;
}

void Bar::setFilled(float _filled) {
    filled = _filled;
    if(filled > BAR_MAX_FILLED) {
        filled = BAR_MAX_FILLED;
    } else if(filled < BAR_MIN_FILLED) {
        filled = BAR_MIN_FILLED;
    }
    foreground->p2.x = p.x + width/2 - getFilledBarX();
}

float Bar::getFilled() {
    return filled;
}

void Bar::increaseFilled(float amount) {
    setFilled(filled + amount);
}

void Bar::decreaseFilled(float amount) {
    setFilled(filled - amount);
}

bool Bar::isFull() {
    return abs(filled - BAR_MAX_FILLED) < 0.0001;
}

bool Bar::isEmpty() {
    return abs(filled - BAR_MIN_FILLED) < 0.0001;
}
