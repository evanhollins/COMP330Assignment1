//
//  Point.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/4/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <math.h>
#include <GLUT/GLUT.h>

class Point {
public:
    int x;
    int y;
    Point(int _x, int _y): x(_x), y(_y) {};
    float distanceTo(int, int);
    float distanceTo(Point *);
    void vertex();
    void translate();
};

#endif /* Point_hpp */
