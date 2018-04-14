//
//  Bar.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Bar.hpp"

Bar::Bar(int _x, int _y, int _width, int _height, Color::Color _color) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    filled = BAR_MIN_FILLED;
    
    background = new Rectangle(x, y, width, height, Color::BLACK);
    foreground = new Rectangle(getFilledBarX(), y, getFilledBarWidth(), height - PADDING * 2, color);
}

Bar::~Bar() {
}

void Bar::draw() {
    background->draw();
    foreground->draw();
}

float Bar::getFilledBarWidth() {
    return (width - (PADDING * 2)) * filled;
}

float Bar::getFilledBarX() {
    return ((width - (PADDING * 2)) * (1 - filled)) / 2 + x;
}

void Bar::setFilled(float _filled) {
    filled = fmax(fmin(_filled, BAR_MAX_FILLED), BAR_MIN_FILLED);
    foreground->p.x = getFilledBarX();
    foreground->size_x = round(getFilledBarWidth());
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
    return filled == BAR_MAX_FILLED;
}

bool Bar::isEmpty() {
    return filled == BAR_MIN_FILLED;
}
