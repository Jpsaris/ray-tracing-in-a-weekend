#ifndef RTWEEKEND_H_
#define RTWEEKEND_H_

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include <random>

// Constants

const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385;

// Utility Functions

inline float degrees_to_radians(float degrees) { return degrees * pi / 180.0; }

inline float random_float() {
  // Returns a random real in [0, 1).
  static std::uniform_real_distribution<float> distribution(0.0, 1.0);
  static std::mt19937 generator;
  return distribution(generator);
  return std::rand() / (RAND_MAX + 1.0);
}

inline float random_float(float min, float max) {
  // Returns a random real in [min, max).
  return min + (max - min) * random_float();
}

#endif // RTWEEKEND_H_
