//
//  SESBase.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/4/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "SESBase.hpp"

SESBase::SESBase(int _x, int _y) {
    location = new Point(_x, _y);
    
    shapes.add(new Rectangle(_x,
                                   _y,
                                   160,
                                   160,
                                   Color::GRAY));
    shapes.add(new ClosedCircle(_x,
                                      _y,
                                      70,
                                      Color::WHITE));
    shapes.add(new ClosedCircle(_x,
                                      _y,
                                      60,
                                      Color::GRAY));
    shapes.add(new Line(_x - 20,
                              _y,
                              _x + 20,
                              _y,
                              4,
                              Color::WHITE));
    
    shapes.add(new Line(_x - 20,
                              _y + 30,
                              _x - 20,
                              _y - 30,
                              4,
                              Color::WHITE));
    
    shapes.add(new Line(_x + 20,
                              _y + 30,
                              _x + 20,
                              _y - 30,
                              4,
                              Color::WHITE));
}

SESBase::~SESBase() {
    delete location;
}

bool SESBase::contains(int _x, int _y) {
    return shapes.contains(_x, _y);
}

void SESBase::draw() {
    shapes.draw();
}

