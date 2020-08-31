#include <iostream>
#include "ray.hpp"

namespace ray
{
Ray::Ray(tuple::Tuple origin_, tuple::Tuple vector_)
    : origin(origin_)
    , vector(vector_)
{
}

Ray::~Ray(void)
{
}

tuple::Tuple Ray::pose(double t)
{
    return origin + vector * t;
}

Ray transform(Ray r, matrix::Matrix m)
{
    return Ray(matrix::tuple_multiply(m, r.origin), matrix::tuple_multiply(m, r.vector));
}

} // namespace ray