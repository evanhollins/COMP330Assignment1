//
//  Color.h
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/15/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include <stdio.h>

#ifndef Color_h
#define Color_h

class Color {
private:
    float r;
    float g;
    float b;
    float a;
public:
    Color(float _r, float _g, float _b, float _a);
    float getR();
    float getG();
    float getB();
    float getA();
    void setR(float x);
    void setG(float x);
    void setB(float x);
    void setA(float x);
    
};
Color::Color(float _r, float _g, float _b, float _a) {
    this->r = _r;
    this->g = _g;
    this->b = _b;
    this->a = _a;
}
float Color::getR() {
    return r;
}

float Color::getG() {
    return g;
}

float Color::getB() {
    return b;
}

float Color::getA() {
    return a;
}

void Color::setR(float x) {
    if (x > 1.0) {
        r = 1.0;
    } else if(x < 0.0) {
        r = 0.0;
    } else {
        r = x;
    }
}

void Color::setG(float x) {
    if (x > 1.0) {
        g = 1.0;
    } else if(x < 0.0) {
        g = 0.0;
    } else {
        g = x;
    }
}

void Color::setB(float x) {
    if (x > 1.0) {
        b = 1.0;
    } else if(x < 0.0) {
        b = 0.0;
    } else {
        b = x;
    }
}

void Color::setA(float x) {
    if (x > 1.0) {
        a = 1.0;
    } else if(x < 0.0) {
        a = 0.0;
    } else {
        a = x;
    }
}

#endif
