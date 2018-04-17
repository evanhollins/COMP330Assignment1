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
    
    lake = new Lake(860, 670, 70);
    
    base = new SESBase(80, 80);
    
    road = new Road(Point(0, y/2 - 75), Point(x, y/2 + 75));
    
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
        trees.add(new Tree((i + 1) * houseSpacing, houseTopRowY - 20));
        houses.add(new House(i * houseSpacing + houseOffset, houseBottomRowY, houseSize));
        trees.add(new Tree((i + 1) * houseSpacing, houseBottomRowY + 20));
    }
    
    for (auto s : houses.get()) {
        flamables.push_back((Flamable *) s);
    }
    for (auto s : trees.get()) {
        flamables.push_back((Flamable *) s);
    }
    
    // Set fire to two random houses
    House * temp = (House *) houses.get(rand() % houses.size());
    temp->setFire();
    temp = (House *) houses.get(rand() % houses.size());
    temp->setFire();
}

Map::~Map() {
}

void Map::draw() {
    shapes.draw();
    houses.draw();
    trees.draw();
}

void Map::update() {
    vector<Flamable *> thingsOnFire;
    for(auto f: flamables) {
        if(f->onFire && f->fireCanSpread()) {
            thingsOnFire.push_back(f);
        }
    }
    for(auto f: thingsOnFire) {
        for(auto s: flamables) {
            if(f->getPoint().distanceTo(s->getPoint()) <= 150) {
                s->setFire();
            }
        }
    }
    
    houses.update();
    shapes.update();
    trees.update();
}

void Map::changeSize(int _x, int _y) {
    x = _x;
    y = _y;
    
    road->update(Point(0, y/2 - 75), Point(x, y/2 + 75));
}

bool Map::inLake(int _x, int _y) {
    return lake->contains(_x, _y);
}

bool Map::inBase(int _x, int _y) {
    return base->contains(_x, _y);
}

void Map::water(int _x, int _y) {
    for(auto s: flamables) {
        if(s->getPoint().distanceTo(_x, _y) < 50) {
            s->water();
        }
    }
}
