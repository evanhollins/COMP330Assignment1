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
    
    lake = new Lake(LAKE_X, LAKE_Y, LAKE_SIZE);
    
    base = new SESBase(SES_BASE_X, SES_BASE_Y);
    
    road = new Road(Point(0, ROAD_X - ROAD_SIZE/2), Point(x, ROAD_X + ROAD_SIZE/2));
    
    shapes.add(lake);
    shapes.add(base);
    shapes.add(road);
    
    int houseTopRowY = ROAD_X - ROAD_SIZE;
    int houseBottomRowY = ROAD_X + ROAD_SIZE;
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
    
    // Set fire to two random things
    Flamable * temp = flamables[rand() % houses.size()];
    temp->setFire();
    temp = flamables[rand() % houses.size()];
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
            if(f->getPoint().distanceTo(s->getPoint()) <= FIRE_SPREAD_RADIUS) {
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
    
    road->update(Point(0, ROAD_X - ROAD_SIZE/2), Point(x, ROAD_X + ROAD_SIZE/2));
}

bool Map::inLake(int _x, int _y) {
    return lake->contains(_x, _y);
}

bool Map::inBase(int _x, int _y) {
    return base->contains(_x, _y);
}

void Map::water(int _x, int _y) {
    for(auto s: flamables) {
        if(s->getPoint().distanceTo(_x, _y) < WATER_SPREAD_RADIUS) {
            s->water();
        }
    }
}
