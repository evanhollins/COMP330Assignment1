//
//  Map.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/5/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <vector>

#include "Shape.hpp"
#include "SESBase.hpp"
#include "Lake.hpp"
#include "Road.hpp"
#include "House.hpp"

class Map {
private:
    SESBase * base;
    Lake * lake;
    Road * road;
    Shapes houses;
    Shapes shapes;
    int x;
    int y;
    
public:
    Map(int _x, int _y);
    ~Map();
    void draw();
    void update();
    void changeSize(int _x, int _y);
    bool inLake(int _x, int _y);
    bool inBase(int _x, int _y);
};

#endif /* Map_hpp */
