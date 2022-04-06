/*
Copyright 2021 Robin Simpson (teachmetheways652@gmail.com)
kaylon.cpp (c) 2021
Desc: Kaylon integration
Created:  2021-07-12T21:48:58.976Z
*/

#include "kaylon.h"

Kaylon::Kaylon(double h, double w) : Humanoid(h, w), _isFiring(false) {
}

bool Kaylon::isFiring() {
    return _isFiring;
}

void Kaylon::startFiring() {
    _isFiring = true;
}

void Kaylon::stopFiring() {
    _isFiring = false;
}