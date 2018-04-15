//
//  Drawable.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Shape.hpp"

Shape::Shape() {
    p = Point(0, 0);
}

Point Shape::getPoint() {
    return p;
}

void Shape::setPoint(Point p) {
    this->p = p;
}

void Shape::setPoint(int x, int y) {
    p.x = x;
    p.y = y;
}

Shapes::Shapes() {
    
}

Shapes::~Shapes() {
    for(int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
}

void Shapes::add(Shape * shape) {
    shapes.push_back(shape);
}

void Shapes::draw() {
    forEach([](Shape * s) {s->draw();});
}

void Shapes::update() {
    forEach([](Shape * s) {s->update();});
}

bool Shapes::contains(int x, int y) {
    for (int i = 0; i < shapes.size(); i++) {
        if(shapes[i]->contains(x, y)) {
            return true;
        }
    }
    return false;
}

unsigned long Shapes::size() {
    return shapes.size();
}

Shape * Shapes::get(int i) {
    return shapes[i];
}

void Shapes::forEach(void (*func) (Shape *)) {
    for (int i = 0; i < shapes.size(); i++) {
        func(shapes[i]);
    }
}

std::vector<Shape *> Shapes::get() {
    return shapes;
}
