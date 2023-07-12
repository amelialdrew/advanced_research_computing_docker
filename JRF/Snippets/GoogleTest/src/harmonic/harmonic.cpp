#include "harmonic.hpp"

/**
 * @brief Adds the reciprocals of two numbers, and returns the reciprocal of
 * that
 *
 * @param x First input number
 * @param y Second input number
 * @return The result of the calculation
 */
double harmonic::harm_add(double x, double y) {
  double xp, yp, zp;

  xp = 1e0 / x;
  yp = 1e0 / y;
  zp = xp + yp;

  return 1e0 / zp;
}
