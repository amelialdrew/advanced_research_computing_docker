#include <iostream>
#include "harmonic.hpp"

int main() {

    double x,y,z;

    x = 20e0;
    y = 5e0;

    z = harmonic::harm_add(x,y);

    std::cout << "Output:" << x << " + " << y << " = " << z << std::endl;

    return 0;
}