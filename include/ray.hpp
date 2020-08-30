#ifndef RAY_HPP_
#define RAY_HPP_

#include "shape.hpp"
#include "tuple.hpp"

namespace ray
{
struct Ray
{
public:
    Ray(tuple::Tuple origin_, tuple::Tuple vector_);
    ~Ray(void);

    tuple::Tuple pose(double t);

    tuple::Tuple origin;
    tuple::Tuple vector;
};

std::vector<double> intersect(shape::Sphere s, Ray r);
// bool hit(shape::Sphere s, Ray r);

} // namespace ray

#endif // RAY_HPP_
