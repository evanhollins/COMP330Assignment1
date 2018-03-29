//
//  Drawable.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Drawable_hpp
#define Drawable_hpp

#include <stdio.h>

#include "Color.hpp"

class Drawable {
public:
    virtual ~Drawable() {};
    virtual void draw() {};
    virtual void update() {};
    
};

#endif /* Drawable_hpp */
