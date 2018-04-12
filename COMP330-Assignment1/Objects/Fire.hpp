//
//  Fire.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/12/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Fire_hpp
#define Fire_hpp

#include <stdio.h>
#include <vector>

#include "Shape.hpp"
#include "Color.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"

#define FIRE_SIZE 18

class Fire: public Shape {
public:
    int x;
    int y;
    std::vector<Shape *> shapes;
    Fire(int x, int y);
    ~Fire();
    void update() {};
    void draw();
    bool contains(int _x, int _y);

};

#endif /* Fire_hpp */
