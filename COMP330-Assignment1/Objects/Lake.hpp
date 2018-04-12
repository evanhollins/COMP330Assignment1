//
//  Lake.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Lake_hpp
#define Lake_hpp

#include <stdio.h>
#include <vector>

#include "Color.hpp"
#include "Shape.hpp"
#include "Circle.hpp"

class Lake: public Shape {
private:
    std::vector<Shape *> shapes;
public:
    int x;
    int y;
    int size;
    Lake(int _x, int _y, int _size);
    ~Lake();
    void draw();
    void update() {};
    bool contains(int _x, int _y);
};
#endif /* Lake_hpp */
