/*
Copyright 2021 Robin Simpson (teachmetheways652@gmail.com)
moclan.cpp (c) 2021
Desc: Moclan integration
Created:  2021-07-12T21:49:07.944Z
*/

#include "moclan.h"

Moclan::Moclan(double h, double w) : Humanoid(h, w) {
    if (h == 0 && w == 0) {
        _isEgg = true;
    }
    else {
        _isEgg = false;
    }
}

/*moclanEgg::moclanEgg() : _isEgg(true) {
}
*/

Moclan Moclan::layEgg() {
    Moclan moclanEgg(0, 0);
    return moclanEgg;
}

void Moclan::hatch() {
    _isEgg = false;
}

bool Moclan::isEgg() {
    return _isEgg;
}
