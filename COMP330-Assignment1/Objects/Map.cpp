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
    
    lake = new Lake(800, 650, 70);
    
    base = new SESBase(80, 80);
    
    road = new Road(Point(x / 2, y / 2), x, 150);
    
    shapes.add(lake);
    shapes.add(base);
    shapes.add(road);
    
    int houseTopRowY = y / 2 - 150;
    int houseBottomRowY = y / 2 + 150;
    int houseSize = 80;
    int houseSpacing = houseSize * 2;
    int houseOffset = houseSize;
    int numberOfHouses = 6;
    
    for (int i = 0; i < numberOfHouses; i++) {
        houses.add(new House(i * houseSpacing + houseOffset, houseTopRowY, houseSize));
        houses.add(new House(i * houseSpacing + houseOffset, houseBottomRowY, houseSize));
    }
    
    
}

Map::~Map() {
}

void Map::draw() {
    shapes.draw();
    houses.draw();
}

void Map::update() {
    houses.update();
    shapes.update();
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
