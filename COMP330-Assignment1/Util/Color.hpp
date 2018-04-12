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
    
}

/*
class Color {
private:
    float r;
    float g;
    float b;
    float a;
    Color(float _r, float _g, float _b);
public:
    Color();
    float getR();
    float getG();
    float getB();
    float getA();
    void setR(float x);
    void setG(float x);
    void setB(float x);
    void setA(float x);
    void set();
    
    static Color WHITE() {return {1.0, 1.0, 1.0};};
    static Color BLACK() {return {0.0, 0.0, 0.0};};
    static Color GRAY() {return {0.77, 0.77, 0.77};};
    static Color FUEL() {return {1.0, 0.86, 0.5};};
    static Color WATER() {return {0.44, 0.63, 0.93};};
    static Color RED() {return {1.0, 0.0, 0.0};};
    static Color BACKGROUND() {return {0.78, 0.66, 0.33};};
    
};
 */

#endif
