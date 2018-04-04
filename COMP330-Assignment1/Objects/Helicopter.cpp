//
//  Helicopter.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/20/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//
#include "Helicopter.hpp"


Helicopter::Helicopter(int _x, int _y, int _size) {
    location = new Point(_x, _y);
    target = new Point(_x, _y);
    setSize(_size);
    setAngle(0);
    setTargetAngle(0);
    bodyColor = new Color(0.2, 0.2, 0.2);
    propColor = new Color(0.5, 0.5, 0.5);
    pathColor = new Color(1.0, 0.0, 0.0);
    // Body
    shapes.push_back(new ClosedCircle(0, 0, size/2, bodyColor));
    shapes.push_back(new Rectangle(-size/2, 0, size, size/4, bodyColor));
    shapes.push_back(new Rectangle(-size, 0, size / 8, size / 2, bodyColor));
    // Prop
    propellor = new Propellor(0, 0, size, propColor);
    //Path
    path = new Line(target, location, 2, pathColor);
    path->dashed = true;
}

Helicopter::~Helicopter() {
    delete bodyColor;
    delete propColor;
    for(int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
}

void Helicopter::draw() {
    glPushMatrix();
    location->translate();
    glRotatef(angle, 0, 0, 1);
    for(int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
    glPopMatrix();
    glPushMatrix();
    location->translate();
    propellor->draw();
    glPopMatrix();
    if(location->distanceTo(target) > size/2) {
        path->draw();
    }
}

void Helicopter::update() {
    if(location->distanceTo(target) > HELICOPTER_DEADBAND) {
        
        location->x += limit(target->x - location->x, HELICOPTER_MAX_SPEED);
        location->y += limit(target->y - location->y, HELICOPTER_MAX_SPEED);
        setAngle(angle + limit(modDif(targetAngle,
                                      angle,
                                      FULL_CIRCLE_DEG),
                               HELICOPTER_MAX_ANGLE_CHANGE));
        
    }
    for(int i = 0; i < shapes.size(); i++) {
        shapes[i]->update();
    }
    propellor->update();
}

int Helicopter::getX() {
    return location->x;
}

int Helicopter::getY() {
    return location->y;
}

int Helicopter::getTargetX() {
    return target->x;
}

int Helicopter::getTargetY() {
    return target->y;
}

int Helicopter::getTargetAngle() {
    return targetAngle;
}

int Helicopter::getSize() {
    return size;
}

int Helicopter::getAngle() {
    return angle;
}

void Helicopter::setX(int _x) {
    location->x = _x;
}

void Helicopter::setY(int _y) {
    location->y = _y;
}

void Helicopter::setTargetX(int _x) {
    target->x= _x;
}

void Helicopter::setTargetY(int _y) {
    target->y = _y;
}

void Helicopter::setTargetAngle(int _angle) {
    targetAngle = mod(_angle, FULL_CIRCLE_DEG);
}

void Helicopter::setSize(int _size) {
    size = _size;
}

void Helicopter::setAngle(int _angle) {
    angle = mod(_angle, FULL_CIRCLE_DEG);
}

void Helicopter::setSpeed(int _speed) {
    speed = min(abs(_speed), HELICOPTER_MAX_SPEED);
}

int Helicopter::getSpeed() {
    return speed;
}

