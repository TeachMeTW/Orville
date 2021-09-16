/*
Copyright 2021 Robin Simpson (teachmetheways652@gmail.com)
kaylon.h (c) 2021
Desc: Kaylon class
Created:  2021-07-12T21:49:16.944Z
*/

#ifndef SPECIES_KAYLON_H_
#define SPECIES_KAYLON_H_

#include "species/humanoid.h"

class Kaylon : public Humanoid {
 private:
  bool _isFiring;

 public:
  Kaylon(double, double);
  void startFiring();
  void stopFiring();
  bool isFiring();
};

#endif  // SPECIES_KAYLON_H_
