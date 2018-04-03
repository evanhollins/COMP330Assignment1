//
//  MathUtil.hpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#ifndef MathUtil_hpp
#define MathUtil_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>

#define FULL_CIRCLE_DEG 360
#define THREE_QUATER_CIRCLE_DEG 270
#define HALF_CIRLCE_DEG 180
#define QUARTER_CIRCLE_DEG 90

int quadrantSignX(int angle);
int quadrantSignY(int angle);
float deg(float rad);
float rad(float deg);
int sign(int x);
int abs(int _x);
int mod(int _x, int _mod);
int modDif(int _x, int _y, int _mod);
int limit(int _x, int limit);

#endif /* MathUtil_hpp */
