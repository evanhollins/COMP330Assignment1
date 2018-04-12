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
    virtual void draw() =0;
    virtual void update()=0;
    virtual bool contains(int, int) =0;
};

#endif /* Shape_hpp */
