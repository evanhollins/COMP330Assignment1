//
//  Bar.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Bar.hpp"

Bar::Bar(int _x, int _y, int _width, int _height, Color::Color _color, string _text) {
    setPoint(_x, _y);
    width = _width;
    height = _height;
    filled = BAR_MIN_FILLED;
    color = _color;
    text = _text;
    textColor = Color::BLACK;
    
    background = new Rectangle(p.x, p.y, width, height, Color::BLACK);
    Point foregroundTopRight = Point(p.x + width/2 - PADDING, p.y + height/2 - PADDING);
    Point foregroundBottomLeft = Point(p.x + width/2 - getFilledBarX(), p.y - height/2 + PADDING);
    foreground = new Rectangle(foregroundTopRight, foregroundBottomLeft, color);
}

Bar::~Bar() {
}

void Bar::draw() {
    textColor.set();
    glPushMatrix();
    glRasterPos2i(p.x, p.y - TEXT_Y_OFFSET);
    for (auto c : text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
    glPopMatrix();
    
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

void Bar::update(int _x, int _y) {
    setPoint(_x, _y);
    
    background->p1.x = _x + width/2;
    background->p1.y = _y + height/2;
    background->p2.x = _x - width/2;
    background->p2.y = _y - height/2;
    
    foreground->p1.x = background->p1.x - PADDING;
    foreground->p1.y = background->p1.y - PADDING;
    foreground->p2.x = p.x + width/2 - getFilledBarX();
    foreground->p2.y = background->p2.y + PADDING;
    
}
