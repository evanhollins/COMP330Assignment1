//
//  House.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/13/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef House_hpp
#define House_hpp

#include <stdio.h>
#include <stdlib.h>

#include "Shape.hpp"
#include "Color.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Fire.hpp"
#include "Flamable.hpp"

#define HOUSE_MAX_FIRE 4
#define HOUSE_MAX_FIRE_CYCLES 600

class House: public Flamable {
private:
    Color::Color roofColorLight;
    Color::Color roofColor;
    Color::Color roofColorDark;
    int size;
    Shapes shapes;
    Shapes burntDownShapes;
public:
    House(int x, int y, int size);
    House(Point p, int size);
    ~House();
    void init();

    void update();
    void draw();
    bool contains(int x, int y);
};

#endif /* House_hpp */
