/**
 * Humanoid implementation.
 *
 * Copyright (c) 2021, Robin Lee Simpson.
*/

#include "species/humanoid.h"

Humanoid::Humanoid(double h, double w) : _height(h), _weight(w) {
}

double Humanoid::height() {
  return _height;
}

double Humanoid::weight() {
  return _weight;
}
