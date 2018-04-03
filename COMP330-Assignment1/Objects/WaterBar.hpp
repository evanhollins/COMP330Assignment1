//
//  WaterBar.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef WaterBar_hpp
#define WaterBar_hpp

#include <stdio.h>
#include <vector>
#include <math.h>

#include "Color.hpp"
#include "Shape.hpp"
#include "Rectangle.hpp"

#define WATER_BAR_MIN_FILLED 0.05
#define WATER_BAR_MAX_FILLED 1
#define PADDING 2

class WaterBar: public Shape {
private:
    Rectangle * background;
    Rectangle * foreground;
    float filled;
public:
    int x;
    int y;
    int height;
    int width;
    Color * color;
    WaterBar(int _x, int _y, int _width, int _height, Color * _color);
    ~WaterBar();
    void draw();
    void update() {};
    bool contains(int _x, int _y) { return false; };
    void setFilled(float _filled);
    float getFilled();
    float getFilledBarWidth();
    float getFilledBarX();
    void increaseFilled(float amount);
    void decreaseFilled(float amount);
    bool isFull();
    bool isEmpty();
};
#endif /* WaterBar_hpp */
