//
//  SESBase.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/4/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef SESBase_hpp
#define SESBase_hpp

#include <stdio.h>
#include <vector>

#include "Point.hpp"
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Line.hpp"

class SESBase: public Shape {
public:
    Point * location;
    int size;
    Shapes shapes;
    SESBase(int _x, int _y);
    ~SESBase();
    void update() {};
    bool contains(int _x, int _y);
    void draw();
};

#endif /* SESBase_hpp */
