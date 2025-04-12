#ifndef RTWEEKEND_H_
#define RTWEEKEND_H_

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include <random>

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) { return degrees * pi / 180.0; }

inline double random_double() {
  // Returns a random real in [0, 1).
  static std::uniform_real_distribution<double> distribution(0.0, 1.0);
  static std::mt19937 generator;
  return distribution(generator);
  return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
  // Returns a random real in [min, max).
  return min + (max - min) * random_double();
}

#endif // RTWEEKEND_H_
