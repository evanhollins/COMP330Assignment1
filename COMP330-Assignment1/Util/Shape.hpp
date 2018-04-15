//
//  Drawable.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/29/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include <vector>

#include "Color.hpp"
#include "Point.hpp"

class Shape {
protected:
    Point p;
    
public:
    Shape();
    virtual ~Shape() {};
    virtual void draw() =0;
    virtual void update()=0;
    virtual bool contains(int, int) =0;
    
    Point getPoint();
    void setPoint(Point p);
    void setPoint(int x, int y);
};

class Shapes: public Shape {
private:
    std::vector<Shape *> shapes;
public:
    Shapes();
    ~Shapes();
    void add(Shape *);
    void draw();
    void update();
    bool contains(int, int);
    unsigned long size();
    Shape * get(int i);
    std::vector<Shape *> get();
    void forEach(void (*func) (Shape *));
};

#endif /* Shape_hpp */
