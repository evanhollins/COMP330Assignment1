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
    
    shapes.push_back(new Rectangle(_x,
                                   _y,
                                   160,
                                   160,
                                   Color::GRAY()));
    shapes.push_back(new ClosedCircle(_x,
                                      _y,
                                      70,
                                      Color::WHITE()));
    shapes.push_back(new ClosedCircle(_x,
                                      _y,
                                      60,
                                      Color::GRAY()));
    shapes.push_back(new Line(_x - 20,
                              _y,
                              _x + 20,
                              _y,
                              4,
                              Color::WHITE()));
    
    shapes.push_back(new Line(_x - 20,
                              _y + 30,
                              _x - 20,
                              _y - 30,
                              4,
                              Color::WHITE()));
    
    shapes.push_back(new Line(_x + 20,
                              _y + 30,
                              _x + 20,
                              _y - 30,
                              4,
                              Color::WHITE()));
}

SESBase::~SESBase() {
    delete location;
    for(int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
}

bool SESBase::contains(int _x, int _y) {
    return shapes[0]->contains(_x, _y);
}

void SESBase::draw() {
    for(int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
}

