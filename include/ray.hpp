#ifndef RAY_HPP_
#define RAY_HPP_

#include "matrix.hpp"
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

// Transform Operations
Ray transform(Ray r, matrix::Matrix m);

} // namespace ray

#endif // RAY_HPP_
