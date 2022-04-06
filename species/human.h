/**
 * Human class.
 *
 * Copyright (c) 2021, Robin Lee Simpson.
*/
#ifndef SPECIES_HUMAN_H_
#define SPECIES_HUMAN_H_

#include "humanoid.h"

class Human : public Humanoid {
 private:
  bool _isMale;

 public:
  Human(bool, double, double);
  bool isMale();
};

#endif  // SPECIES_HUMAN_H_
