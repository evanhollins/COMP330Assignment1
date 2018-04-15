//
//  MathUtil.cpp
//  COMP330-Assignment1
//
//  Created by Evan Hollins on 4/3/18.
//  Copyright © 2018 Evan Hollins. All rights reserved.
//

#include "MathUtil.hpp"

int quadrantSignX(int angle) {
    if(angle >= HALF_CIRLCE_DEG) {
        return -1;
    }
    return 1;
}

int quadrantSignY(int angle) {
    if(angle >= QUARTER_CIRCLE_DEG && angle < THREE_QUATER_CIRCLE_DEG) {
        return -1;
    }
    return 1;
}

float deg(float rad) {
    return rad * HALF_CIRLCE_DEG / M_PI;
}

float rad(float deg) {
    return deg * M_PI / HALF_CIRLCE_DEG;
}

int sign(int x) {
    if(x < 0) {
        return -1;
    }
    return 1;
}

int abs(int _x) {
    if(_x < 0) {
        return _x * -1;
    }
    return _x;
}

int mod(int _x, int _mod) {
    if(_x < 0) {
        return _mod - (abs(_x) % _mod);
    }
    return _x % _mod;
}

int modDif(int _x, int _y, int _mod) {
    if(abs(_x - _y) > abs(_mod / 2)) {
        return mod(_x - _y, _mod) * sign(_y - _x);
    } else {
        return _x - _y;
    }
}

int limit(int _x, int _limit) {
    return fmin(abs(_x), abs(_limit)) * sign(_x);
}

bool inRange(int x, int limit1, int limit2) {
    if(limit1 > limit2) {
        return x <= limit1 && x >= limit2;
    }
    return x >= limit1 && x <= limit2;
}
