//
//  main.h
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 3/15/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef main_h
#define main_h

#include <stdio.h>
#include <iostream>
#include <GLUT/GLUT.h>
using namespace std;

#include "Color.hpp"
#include "Helicopter.hpp"

#define FRAMERATE 60 // Frames per second
#define MILLISECONDS_PER_SECOND 1000
#define WINDOW_SIZE_X 500
#define WINDOW_SIZE_Y 500
#define BACKGROUND_R 0.78
#define BACKGROUND_G 0.66
#define BACKGROUND_B 0.33
#define BACKGROUND_A 0.0

#define HELICOPTER_SIZE 50

Color * background;
Helicopter * helicopter;


#endif /* main_h */
