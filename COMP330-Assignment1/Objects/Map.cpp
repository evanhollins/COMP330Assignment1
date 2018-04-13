//
//  Map.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/5/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Map.hpp"

Map::Map(int _x, int _y) {
    x = _x;
    y = _y;
    
    lake = new Lake(600, 600, 40);
    
    base = new SESBase(80, 80);
    
    road = new Road(Point(x / 2, y / 2), x, 150);
    
    shapes.push_back(lake);
    shapes.push_back(base);
    shapes.push_back(road);
    
}

Map::~Map() {
    for(int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
}

void Map::draw() {
    for(int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
}

void Map::changeSize(int _x, int _y) {
    x = _x;
    y = _y;
}

bool Map::inLake(int _x, int _y) {
    return lake->contains(_x, _y);
}

bool Map::inBase(int _x, int _y) {
    return base->contains(_x, _y);
}
