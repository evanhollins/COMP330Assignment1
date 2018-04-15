//
//  Animation.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/15/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Animation_hpp
#define Animation_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class Animation {
protected:
    bool running;
    int duration;
    int cycles;
public:
    Animation();
    ~Animation() {};
    virtual void draw()=0;
    virtual void update()=0;
    virtual void start()=0;
    virtual bool contains(int x, int y)=0;
    bool isDone();
};

class Animations {
private:
    std::vector<Animation *> animations;
public:
    Animations();
    ~Animations();
    void add(Animation *);
    void draw();
    void update();
    bool contains(int, int);
    unsigned long size();
    Animation * get(int i);
};

#endif /* Animation_hpp */
