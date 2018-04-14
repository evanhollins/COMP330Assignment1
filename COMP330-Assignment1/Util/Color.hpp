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
    const Color ROAD{0.52, 0.52, 0.52, 1.0};
    const Color FUEL{1.0, 0.86, 0.5, 1.0};
    const Color WATER{0.44, 0.63, 0.93, 1.0};
    const Color RED{1.0, 0.0, 0.0, 1.0};
    const Color BACKGROUND{0.78, 0.66, 0.33, 1.0};
    const Color FIRE_RED{0.95, 0.27, 0.1, 1.0};
    const Color FIRE_ORANGE{0.97, 0.58, 0.07, 1.0};
    const Color FIRE_YELLOW {1.0, 0.91, 0.45, 1.0};
    const Color CLEAR {0.0, 0.0, 0.0, 0.0};
    const Color SHADOW {0.0, 0.0, 0.0, 0.2};
    const Color ROOF_GREEN_LIGHT {0.67, 0.90, 0.20, 1.0};
    const Color ROOF_GREEN {0.65, 0.88, 0.18, 1.0};
    const Color ROOF_GREEN_DARK {0.63, 0.86, 0.16, 1.0};
    const Color ROOF_BRICK_LIGHT {0.83, 0.53, 0.30, 1.0};
    const Color ROOF_BRICK {0.81, 0.51, 0.28, 1.0};
    const Color ROOF_BRICK_DARK {0.79, 0.49, 0.26, 1.0};
    const Color ROOF_TAN_LIGHT {0.88, 0.88, 0.68, 1.0};
    const Color ROOF_TAN {0.86, 0.86, 0.66, 1.0};
    const Color ROOF_TAN_DARK {0.84, 0.84, 0.64, 1.0};
    const Color ROOF_RED_LIGHT {1.0, 0.66, 0.53, 1.0};
    const Color ROOF_RED {0.98, 0.64, 0.51, 1.0};
    const Color ROOF_RED_DARK {0.96, 0.62, 0.49, 1.0};
}

#endif
