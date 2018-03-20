//
//  Helicopter.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/20/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Helicopter_hpp
#define Helicopter_hpp

#include <stdio.h>
#include <iostream>
#include <GLUT/GLUT.h>
using namespace std;

#include "Color.h"

class Helicopter {
private:
    int x;
    int y;
    int angle;
    int size;
    Color * bodyColor;
    
public:
    Helicopter(int _x, int _y, int _size);
    void draw();
    int getX();
    int getY();
    int getSize();
    int getAngle();
    void setX(int _x);
    void setY(int _y);
    void setSize(int _size);
    void setAngle(int _angle);
};

#endif /* Helicopter_hpp */
