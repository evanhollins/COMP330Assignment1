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
#include "Tree.hpp"
#include "Flamable.hpp"

#define LAKE_X 860
#define LAKE_Y 670
#define LAKE_SIZE 70
#define SES_BASE_X 80
#define SES_BASE_Y 80
#define ROAD_X 375
#define ROAD_SIZE 150
#define FIRE_SPREAD_RADIUS 150
#define WATER_SPREAD_RADIUS 50

class Map {
private:
    SESBase * base;
    Lake * lake;
    Road * road;
    Shapes houses;
    Shapes trees;
    Shapes shapes;
    vector<Flamable *> flamables;
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
    void water(int _x, int _y);
};

#endif /* Map_hpp */
