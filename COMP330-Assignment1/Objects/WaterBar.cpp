//
//  WaterBar.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "WaterBar.hpp"

WaterBar::WaterBar(int _x, int _y, int _width, int _height) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    filled = WATER_BAR_MIN_FILLED;
    
    background = new Rectangle(x, y, width, height, Color::BLACK);
    foreground = new Rectangle(getFilledBarX(), y, getFilledBarWidth(), height - PADDING * 2, Color::WATER);
}

WaterBar::~WaterBar() {
}

void WaterBar::draw() {
    background->draw();
    foreground->draw();
}

float WaterBar::getFilledBarWidth() {
    return (width - (PADDING * 2)) * filled;
}

float WaterBar::getFilledBarX() {
    return ((width - (PADDING * 2)) * (1 - filled)) / 2 + x;
}

void WaterBar::setFilled(float _filled) {
    filled = fmax(fmin(_filled, WATER_BAR_MAX_FILLED), WATER_BAR_MIN_FILLED);
    foreground->x = getFilledBarX();
    foreground->size_x = round(getFilledBarWidth());
}

float WaterBar::getFilled() {
    return filled;
}

void WaterBar::increaseFilled(float amount) {
    setFilled(filled + amount);
}

void WaterBar::decreaseFilled(float amount) {
    setFilled(filled - amount);
}

bool WaterBar::isFull() {
    return filled == WATER_BAR_MAX_FILLED;
}

bool WaterBar::isEmpty() {
    return filled == WATER_BAR_MIN_FILLED;
}
