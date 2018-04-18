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
}

void Flamable::updateFire() {
    if(doused) {
        dousedCycles++;
        if (dousedCycles > FIRE_DOUSED_CYCLES) {
            doused = false;
        }
    }
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
    if(!onFire && !doused) {
        onFire = true;
        if(fire.size() > 0) {
            fire.clear();
            for (auto f : potentialFire) {
                f->putOut = false;
            }
        }
        fire.push_back(potentialFire[0]);
    }
}

void Flamable::water() {
    onFire = false;
    for (auto f : fire) {
        f->douse();
    }
    onFireCycles = 0;
    dousedCycles = 0;
    doused = true;
}

bool Flamable::fireCanSpread() {
    return fire.size() > 1 && onFire;
}
