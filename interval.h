#ifndef INTERVAL_H
#define INTERVAL_H

#include "rtweekend.h"

class interval {
public:
  float min, max;

  __device__ interval() : min(+infinity), max(-infinity) {} // Default interval is empty

  __device__ interval(float min, float max) : min(min), max(max) {}

  __device__ float size() const { return max - min; }

  __device__ bool contains(float x) const { return min <= x && x <= max; }

  __device__ bool surrounds(float x) const { return min < x && x < max; }

  __device__ float clamp(float x) const {
    if (x < min)
      return min;
    if (x > max)
      return max;
    return x;
  }
  __device__ static const interval empty() {
    return interval(+infinity, -infinity);
  };
  __device__ static const interval universe() {
    return interval(-infinity, +infinity);
  }
};


#endif
