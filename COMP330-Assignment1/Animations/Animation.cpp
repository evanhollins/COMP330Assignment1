//
//  Animation.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/15/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Animation.hpp"

Animation::Animation() {
    running = false;
    duration = 0;
    cycles = 0;
}

bool Animation::isDone() {
    return !running;
}

Animations::Animations() {
    
}

Animations::~Animations() {
}

void Animations::add(Animation * animation) {
    animations.push_back(animation);
    animations.back()->start();
}

void Animations::update() {
    int i = 0;
    while(i < animations.size()) {
        if(animations[i]->isDone()) {
            animations.erase(animations.begin() + i);
        } else {
            i++;
        }
    }
    for (int i = 0; i < animations.size(); i++) {
        animations[i]->update();
    }
}

void Animations::draw() {
    for (int i = 0; i < animations.size(); i++) {
        animations[i]->draw();
    }
}

bool Animations::contains(int x, int y) {
    for (int i = 0; i < animations.size(); i++) {
        if(animations[i]->contains(x, y)) {
            return true;
        }
    }
    return false;
}

unsigned long Animations::size() {
    return animations.size();
}

Animation * Animations::get(int i) {
    return animations[i];
}
