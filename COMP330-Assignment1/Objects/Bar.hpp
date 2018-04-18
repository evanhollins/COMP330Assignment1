//
//  Bar.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Bar_hpp
#define Bar_hpp

#include <stdio.h>
#include <vector>
#include <math.h>

#include "Color.hpp"
#include "Shape.hpp"
#include "Rectangle.hpp"

#define BAR_MIN_FILLED 0.05
#define BAR_MAX_FILLED 1
#define PADDING 2
#define TEXT_Y_OFFSET 15

class Bar: public Shape {
private:
    Rectangle * background;
    Rectangle * foreground;
    Color::Color color;
    Color::Color textColor;
    float filled;
    string text;
public:
    int height;
    int width;
    Bar(int _x, int _y, int _width, int _height, Color::Color, string text);
    ~Bar();
    void draw();
    void update() {};
    void update(int, int);
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
#endif /* Bar_hpp */

