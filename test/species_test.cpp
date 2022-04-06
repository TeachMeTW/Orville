/**
 * Unit tests for Species.
 *
 * Copyright (c) 2019, Sekhar Ravinutala.
 */

#include "../species/species.h"

// Ignore possible red squggly below (bazel will automatically install gtest)
#include "gtest/gtest.h"

#include <type_traits>
#include <string>
#include <ctime>
#include <cstdlib>
#include <random>


// Namespace to prevent global name clash
namespace {
  time_t now = time(NULL);
  unsigned int seed = std::localtime(&now)->tm_sec;
  char name[10];
}

#define WEIGHT() (100 + (rand() % 200))
#define HEIGHT() (5.0 + (rand() % 16) / 10.0)
const char *crazyName() {
  snprintf(name, sizeof(name), "crazy-%2d", seed);
  return name;
}
// Random data for tests


// Test Eevak
TEST(species, eevak) {
  
  // Default.
  Eevak eevak;
  EXPECT_FALSE(eevak.isRunning());

  // Must not be humanoid.
  EXPECT_FALSE((std::is_base_of<Humanoid, Eevak>::value));

  // Check running.
  eevak.run();
  EXPECT_TRUE(eevak.isRunning());
  if (eevak.isRunning()) {
    std::cout << "Eevak is running" << std::endl;
  }

  // Stop.
  eevak.stop();
  EXPECT_FALSE(eevak.isRunning());
  std::cout << "Stopped Running" << std::endl;
}

// Test Gelatin
TEST(species, gelatin) {
  double weight = WEIGHT();
  std::cout << "\nWeight: " << weight<< std::endl;

  // Create
  Gelatin gelatin(weight);
  EXPECT_EQ(gelatin.weight(), weight);
  EXPECT_STREQ(gelatin.shape(), "sphere");
  std::cout << "Shape: " << gelatin.shape() << std::endl;

  // Must not be humanoid
  EXPECT_FALSE((std::is_base_of<Humanoid, Gelatin>::value));

  std::cout << "Morphing" << std::endl;
  // Ignore all bad morph attempts
  gelatin.morph(crazyName());
  EXPECT_STREQ(gelatin.shape(), "sphere");
  std::cout << "Shape: " << gelatin.shape() << std::endl;

  // Morph to "flat" shape
  gelatin.morph("flat");
  EXPECT_STREQ(gelatin.shape(), "flat");
  std::cout << "Shape: " << gelatin.shape() << std::endl;

  // Go back to default
  gelatin.morph();
  EXPECT_STREQ(gelatin.shape(), "sphere");
  std::cout << "Shape: " << gelatin.shape() << std::endl;

  // Split into two
  std::cout << "Splitting" << std::endl;
  Gelatin newGelatin = gelatin.split();
  if (newGelatin.weight() > 0) {
    std::cout << "Split Success" << std::endl;
  }
  EXPECT_NE(newGelatin, gelatin);
  EXPECT_EQ(gelatin.weight(), weight / 2);
  EXPECT_EQ(newGelatin.weight(), weight / 2);
  EXPECT_STREQ(newGelatin.shape(), gelatin.shape());
}

// Test Human
TEST(species, human) {
  double height = HEIGHT();
  double weight = WEIGHT();
    std::cout << "\nHeight: " << height << std::endl;
  std::cout << "\nWeight: " << weight << std::endl;

  // Create
  Human human(false, height, weight);
  EXPECT_FALSE(human.isMale());
  EXPECT_EQ(human.height(), height);
  EXPECT_EQ(human.weight(), weight);

  // Must be humanoid
  EXPECT_TRUE((std::is_base_of<Humanoid, Human>::value));
}

// Test Kaylon
TEST(species, kaylon) {
  double height = HEIGHT();
  double weight = WEIGHT();
  std::cout << "\nHeight: " << height<< std::endl;
  std::cout << "\nWeight: " << weight<< std::endl;

  // Create
  Kaylon kaylon(height, weight);
  EXPECT_EQ(kaylon.height(), height);
  EXPECT_EQ(kaylon.weight(), weight);
  EXPECT_FALSE(kaylon.isFiring());

  // Must be humanoid
  EXPECT_TRUE((std::is_base_of<Humanoid, Kaylon>::value));

  // Check firing
  kaylon.startFiring();
  EXPECT_TRUE(kaylon.isFiring());
  if (kaylon.isFiring()) {
    std::cout << "Kaylon firing" << std::endl;
  }
  kaylon.stopFiring();
  EXPECT_FALSE(kaylon.isFiring());
  std::cout << "Stopped firing" << std::endl;
}

// Test Moclan
TEST(species, moclan) {
  double height = HEIGHT();
  double weight = WEIGHT();
  std::cout << "\nHeight: " << height<< std::endl;
  std::cout << "\nWeight: " << weight<< std::endl;

  // Create
  Moclan moclan(height, weight);
  EXPECT_EQ(moclan.height(), height);
  EXPECT_EQ(moclan.weight(), weight);
  EXPECT_FALSE(moclan.isEgg());

  // Must be humanoid
  EXPECT_TRUE((std::is_base_of<Humanoid, Moclan>::value));

  // Lay egg
  Moclan moclanEgg = moclan.layEgg();
  EXPECT_FALSE(moclan.isEgg());
  EXPECT_TRUE(moclanEgg.isEgg());
  std::cout << "Lay egg" << std::endl;

  // Hatch
  moclanEgg.hatch();
  std::cout << "Hatch" << std::endl;
  EXPECT_FALSE(moclanEgg.isEgg());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}