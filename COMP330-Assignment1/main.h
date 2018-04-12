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
#include <math.h>
using namespace std;

#include "Color.hpp"
#include "Map.hpp"
#include "Helicopter.hpp"
#include "WaterBar.hpp"
#include "Line.hpp"
#include "Fire.hpp"

#define FRAMERATE 60 // Frames per second
#define MILLISECONDS_PER_SECOND 1000
#define MOUSE_CLICK_DEADBAND 10
#define WINDOW_SIZE_X 1000
#define WINDOW_SIZE_Y 750
#define BACKGROUND_R 0.78
#define BACKGROUND_G 0.66
#define BACKGROUND_B 0.33

#define HELICOPTER_SIZE 50

#define WATER_FILL_RATE 0.01
#define WATER_RELEASE_RATE 0.03

Color::Color background = Color::BACKGROUND;
Map * map;
Helicopter * helicopter;
WaterBar * waterBar;


#endif /* main_h */
