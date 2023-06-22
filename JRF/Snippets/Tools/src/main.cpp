#include <iostream>

#include "harmonic/harmonic.hpp"

/**
 * @brief Main programme which demonstrates the use of the harmonic add function
 *
 * @return int Error code
 */
int main() {
  double xxx, yyy, zzz;

  xxx = 20e0;
  yyy = 5e0;

  zzz = harmonic::harm_add(xxx, yyy);

  std::cout << "Output:" << xxx << " + " << yyy << " = " << zzz << std::endl;

  return 0;
}