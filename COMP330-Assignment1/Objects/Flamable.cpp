//
//  Flamable.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/17/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Flamable.hpp"

Flamable::Flamable(int maxFire, int maxFireCycles) {
    this->maxFire = maxFire;
    this->maxFireCycles = maxFireCycles;
}

Flamable::~Flamable() {
    for (auto f : potentialFire) {
        delete f;
    }
    for (auto f : fire) {
        delete f;
    }
}

void Flamable::updateFire() {
    if(onFire) {
        onFireCycles++;
    }
    if(onFireCycles > maxFireCycles) {
        if(fire.size() >= maxFire) {
            burntDown = true;
            onFire = false;
        } else {
            fire.push_back(potentialFire[fire.size()]);
        }
        onFireCycles = 0;
    }
}

void Flamable::setFire() {
    if(!onFire) {
        onFire = true;
        fire.push_back(potentialFire[0]);
    }
}

void Flamable::water() {
    onFire = false;
    std::for_each(fire.begin(), fire.end(), [](Fire * f) {
        f->douse();
    });
    onFireCycles = 0;
}

bool Flamable::fireCanSpread() {
    return fire.size() > 1;
}
