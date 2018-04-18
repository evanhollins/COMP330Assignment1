//
//  Flamable.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/17/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Flamable_hpp
#define Flamable_hpp

#include <stdio.h>
#include <vector>

#include "Fire.hpp"
#include "Shape.hpp"

#define FIRE_DOUSED_CYCLES 120

class Flamable: public Shape {
protected:
    std::vector<Fire *> potentialFire;
    std::vector<Fire *> fire;
    int onFireCycles = 0;
    int dousedCycles = 0;
    bool doused = false;
    bool burntDown = false;
    int maxFireCycles;
    int maxFire;
public:
    Flamable(int maxFire, int maxFireCycles);
    ~Flamable();
    void updateFire();
    bool onFire = false;
    bool fireCanSpread();
    void setFire();
    void water();
    
    virtual void update()=0;
    virtual void draw()=0;
    virtual bool contains(int, int)=0;
};

#endif /* Flamable_hpp */
