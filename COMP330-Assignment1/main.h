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

#include "Color.h"
#include "Helicopter.h"

#define WINDOW_SIZE_X 500
#define WINDOW_SIZE_Y 500
#define BACKGROUND_R 0.78
#define BACKGROUND_G 0.66
#define BACKGROUND_B 0.33
#define BACKGROUND_A 0.0

Color background(BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, BACKGROUND_A);


#endif /* main_h */
