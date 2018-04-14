//
//  Drawable.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Shape.hpp"

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
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
}

void Shapes::update() {
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->update();
    }
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
