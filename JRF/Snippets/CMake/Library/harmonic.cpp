#include "harmonic.hpp"

double harmonic::harm_add(double x, double y)
{
    double xp, yp, zp;

    xp = 1e0/x;
    yp = 1e0/y;
    zp = xp+yp;
    return 1e0/zp;
}
