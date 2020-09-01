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

tuple::Tuple Sphere::normal(tuple::Tuple point)
{
    tuple::Tuple object_point = matrix::inverse(get_transform()) * point;
    tuple::Tuple object_normal = object_point - origin;
    tuple::Tuple world_normal = matrix::transpose(matrix::inverse(matrix::submatrix(get_transform(), 3, 3))) * object_normal;
    return tuple::normalise(tuple::make_vector(world_normal));
}

} // namespace shape