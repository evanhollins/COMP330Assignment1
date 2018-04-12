//
//  Color.h
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/15/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Color_hpp
#define Color_hpp

#include <stdio.h>
#include <iostream>
#include <GLUT/GLUT.h>

namespace Color {
    struct Color {
        float r;
        float g;
        float b;
        float a;
        void set() {
            glColor4f(r, g, b, a);
        }
    };
    
    const Color WHITE{1.0, 1.0, 1.0, 1.0};
    const Color BLACK{0.0, 0.0, 0.0, 1.0};
    const Color GRAY{0.77, 0.77, 0.77, 1.0};
    const Color FUEL{1.0, 0.86, 0.5, 1.0};
    const Color WATER{0.44, 0.63, 0.93, 1.0};
    const Color RED{1.0, 0.0, 0.0, 1.0};
    const Color BACKGROUND{0.78, 0.66, 0.33, 1.0};
    const Color FIRE_RED{0.95, 0.27, 0.1, 1.0};
    const Color FIRE_ORANGE{0.97, 0.58, 0.07, 1.0};
    const Color FIRE_YELLOW {1.0, 0.91, 0.45, 1.0};
    
}

#endif
