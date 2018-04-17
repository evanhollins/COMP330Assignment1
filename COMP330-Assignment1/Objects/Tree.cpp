//
//  Tree.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/16/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "Tree.hpp"

Tree::Tree(int x, int y): Flamable(TREE_MAX_FIRE, TREE_MAX_FIRE_CYCLES) {
    setPoint(x, y);
    init();
}

Tree::Tree(Point p): Flamable(TREE_MAX_FIRE, TREE_MAX_FIRE_CYCLES) {
    setPoint(p);
    init();
}

Tree::~Tree() {
    
}

void Tree::init() {
    // Normal shapes
    shapes.add(new Rectangle(Point(p.x - 10, p.y), Point(p.x + 10, p.y + 50), Color::TREE_TRUNK));
    shapes.add(new ClosedCircle(p.x - 10, p.y, 20, Color::TREE_LEAVES));
    shapes.add(new ClosedCircle(p.x + 10, p.y, 20, Color::TREE_LEAVES));
    shapes.add(new ClosedCircle(p.x, p.y - 20, 20, Color::TREE_LEAVES));
    
    // Burnt down shapes
    burntDownShapes.add(new ClosedCircle(p.x, p.y, 20, Color::ASHES));
    
    // Fire
    potentialFire.push_back(new Fire(p.x + 10, p.y + 10));
    potentialFire.push_back(new Fire(p.x - 10, p.y - 10));
    // TODO randomize fire
}

void Tree::update() {
    updateFire();
}

void Tree::draw() {
    if(burntDown) {
        burntDownShapes.draw();
    } else {
        shapes.draw();
        for (auto f : fire) {
            f->draw();
        }
    }
}

bool Tree::contains(int x, int y) {
    if(burntDown) {
        return burntDownShapes.contains(x, y);
    }
    return shapes.contains(x, y);
}
