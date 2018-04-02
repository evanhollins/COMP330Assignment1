//
//  Drawable.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>

#include "Color.hpp"

class Shape {
public:
    virtual ~Shape() {};
    virtual void draw() {};
    virtual void update() {};
    virtual bool contains(int _x, int _y) {return false;};
};

#endif /* Shape_hpp */
