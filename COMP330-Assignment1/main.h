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
#include "Bar.hpp"
#include "Line.hpp"
#include "Road.hpp"

#define FRAMERATE 60 // Frames per second
#define MILLISECONDS_PER_SECOND 1000
#define MOUSE_CLICK_DEADBAND 10
#define WINDOW_SIZE_X 1000
#define WINDOW_MIN_SIZE_X 800
#define WINDOW_SIZE_Y 750
#define WINDOW_MIN_SIZE_Y 550
#define BACKGROUND_R 0.78
#define BACKGROUND_G 0.66
#define BACKGROUND_B 0.33

#define FUELBAR_X -60
#define FUELBAR_Y 40
#define FUELBAR_SIZE_X 100
#define FUELBAR_SIZE_Y 20
#define WATERBAR_X -60
#define WATERBAR_Y 85
#define WATERBAR_SIZE_X 100
#define WATERBAR_SIZE_Y 20


#define HELICOPTER_SIZE 50

#define WATER_FILL_RATE 0.01
#define WATER_RELEASE_RATE 0.1
#define WATER_RELEASE_COUNT_MAX 45
#define FUEL_RELEASE_RATE 0.0003
#define FUEL_FILL_RATE 0.01

Color::Color background = Color::BACKGROUND;
Map * map;
Helicopter * helicopter;
Bar * waterBar;
Bar * fuelBar;

#endif /* main_h */
