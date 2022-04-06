/*
Copyright 2021 Robin Simpson (teachmetheways652@gmail.com)
moclan.h (c) 2021
Desc: Moclan class
Created:  2021-07-12T21:49:21.536Z
*/

#ifndef SPECIES_MOCLAN_H_
#define SPECIES_MOCLAN_H_

#include "humanoid.h"

class Moclan : public Humanoid {
 private:
  bool _isEgg;

 public:
  Moclan(double, double);
  bool isEgg();
  Moclan layEgg();
  void hatch();
};

/*class moclanEgg : public Moclan {
 private:
  bool _isEgg;
  bool _hatched;
 public:
  moclanEgg();
  void hatch();
  bool isEgg();
};
*/

#endif  // SPECIES_MOCLAN_H_
