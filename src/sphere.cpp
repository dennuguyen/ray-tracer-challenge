#include "sphere.hpp"

namespace shape
{
Sphere::Sphere(void) : Sphere(tuple::make_point(0.0, 0.0, 0.0), 1.0) {}

Sphere::Sphere(tuple::Tuple origin_, double radius_)
    : origin(origin_)
    , radius(radius_)
{
    empty = false;
}

Sphere::~Sphere() {}

const tuple::Tuple Sphere::get_origin() { return origin; }
const double Sphere::get_radius() { return radius; }
} // namespace shape