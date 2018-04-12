//
//  FuelBar.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/11/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "FuelBar.hpp"

FuelBar::FuelBar(int _x, int _y, int _width, int _height) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    filled = FUEL_BAR_MIN_FILLED;
    
    background = new Rectangle(x, y, width, height, Color::BLACK);
    foreground = new Rectangle(getFilledBarX(), y, getFilledBarWidth(), height - PADDING * 2, Color::FUEL);
}

FuelBar::~FuelBar() {
    delete background;
    delete foreground;
}

void FuelBar::draw() {
    background->draw();
    foreground->draw();
}

float FuelBar::getFilledBarWidth() {
    return (width - (PADDING * 2)) * filled;
}

float FuelBar::getFilledBarX() {
    return ((width - (PADDING * 2)) * (1 - filled)) / 2 + x;
}

void FuelBar::setFilled(float _filled) {
    filled = fmax(fmin(_filled, FUEL_BAR_MAX_FILLED), FUEL_BAR_MIN_FILLED);
    foreground->x = getFilledBarX();
    foreground->size_x = round(getFilledBarWidth());
}

float FuelBar::getFilled() {
    return filled;
}

void FuelBar::increaseFilled(float amount) {
    setFilled(filled + amount);
}

void FuelBar::decreaseFilled(float amount) {
    setFilled(filled - amount);
}

bool FuelBar::isFull() {
    return filled == FUEL_BAR_MAX_FILLED;
}

bool FuelBar::isEmpty() {
    return filled == FUEL_BAR_MIN_FILLED;
}
