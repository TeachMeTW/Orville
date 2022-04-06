/**
 * Gelatin implementation.
 *
 * Copyright (c) 2021, Robin Lee Simpson.
*/

#include "gelatin.h"

Gelatin::Gelatin(double w, std::string s) : _weight(w), _shape(s) {
}

double Gelatin::weight() {
  return _weight;
}

const char *Gelatin::shape() {
  return _shape.c_str();
}

void Gelatin::morph(std::string s) {
  if (s != "sphere" && s != "flat") {
    return;
  }
  _shape = s;
}

void Gelatin::morph() {
  _shape = "sphere";
}

Gelatin Gelatin::split() {
  return Gelatin(_weight /= 2, _shape);
}

bool Gelatin::operator!=(const Gelatin &g) const {
  return this != &g;
}
