#include "shape.hpp"

namespace shape
{
int global_id = 0;

Shape::Shape(void) : id(global_id++)
{
}

Sphere::Sphere(void)
    : origin(tuple::make_point(0.0, 0.0, 0.0))
    , radius(1.0)
{
}

Sphere::Sphere(tuple::Tuple origin_, double radius_) 
    : origin(origin_)
    , radius(radius_)
{
}

} // namespace shape