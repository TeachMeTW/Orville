/**
 * Humanoid declarations.
 *
 * Copyright (c) 2021, Robin Lee Simpson.
*/

#ifndef SPECIES_HUMANOID_H_
#define SPECIES_HUMANOID_H_

class Humanoid {
 private:
  double _height, _weight;

 public:
  Humanoid(double, double);
  double height();
  double weight();
};

#endif  // SPECIES_HUMANOID_H_
