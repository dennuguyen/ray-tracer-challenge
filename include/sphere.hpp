#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "shades.hpp"
#include "shape.hpp"
#include "tuple.hpp"

namespace shape
{
class Sphere : public Shape
{
public:
    Sphere(void);
    Sphere(tuple::Tuple origin_, double radius_);
    Sphere(matrix::Matrix transform_, shades::Material material_, tuple::Tuple origin_, double radius_);
    Sphere(matrix::Matrix transform_, shades::Material material_);
    ~Sphere();

    const tuple::Tuple get_origin();
    const double get_radius();

    tuple::Tuple normal(tuple::Tuple point);

private:
    tuple::Tuple origin;
    double radius;
};

} // namespace shape

#endif // SPHERE_HPP_
