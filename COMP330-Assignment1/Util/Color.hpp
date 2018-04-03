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
using namespace std;


class Color {
private:
    float r;
    float g;
    float b;
    float a;
public:
    Color(float _r, float _g, float _b, float _a);
    Color(float _r, float _g, float _b);
    void update() {};
    float getR();
    float getG();
    float getB();
    float getA();
    void setR(float x);
    void setG(float x);
    void setB(float x);
    void setA(float x);
    void set();
    
};

#endif
