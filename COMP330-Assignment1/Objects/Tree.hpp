//
//  Tree.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/16/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <vector>

#include "Shape.hpp"
#include "Point.hpp"
#include "Fire.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Flamable.hpp"

#define TREE_MAX_FIRE 2
#define TREE_MAX_FIRE_CYCLES 600

class Tree: public Flamable {
    Shapes shapes;
    Shapes burntDownShapes;
    
public:
    Tree(int x, int y);
    Tree(Point p);
    ~Tree();
    void init();
    
    void update();
    void draw();
    bool contains(int x, int y);
    
};

#endif /* Tree_hpp */
