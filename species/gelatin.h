/**
 * Gelatin declarations.
 *
 * Copyright (c) 2021, Robin Lee Simpson.
*/

#ifndef SPECIES_GELATIN_H_
#define SPECIES_GELATIN_H_

#include <string>

class Gelatin {
 private:
  double _weight;
  std::string _shape;

 public:
  explicit Gelatin(double, std::string = "sphere");
  double weight();
  const char *shape();
  void morph(const std::string);
  void morph();
  Gelatin split();
  bool operator!=(const Gelatin &) const;
};

#endif  // SPECIES_GELATIN_H_
