#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "shape.hpp"
#include "tuple.hpp"

namespace shape
{
class Sphere : public Shape
{
public:
    Sphere(void);
    Sphere(tuple::Tuple origin_, double radius_);
    ~Sphere();

    const tuple::Tuple get_origin();
    const double get_radius();

    tuple::Tuple normal(tuple::Tuple point) override;

private:
    tuple::Tuple origin;
    double radius;
};

} // namespace shape

#endif // SPHERE_HPP_
