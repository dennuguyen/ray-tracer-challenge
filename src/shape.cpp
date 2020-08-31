#include "shape.hpp"

#include <cmath>

namespace shape
{
int global_id = 0;

Shape::Shape(void) : empty(true), id(global_id++) {}

int Shape::get_id() { return id; }

bool is_same_shape_object(Shape a, Shape b) { return a.get_id() == b.get_id(); }

Sphere::Sphere(void)
    : origin(tuple::make_point(0.0, 0.0, 0.0))
    , radius(1.0)
{
    empty = false;
}

Sphere::Sphere(tuple::Tuple origin_, double radius_)
    : origin(origin_)
    , radius(radius_)
{
    empty = false;
}

Sphere::~Sphere() {}

tuple::Tuple Sphere::get_origin() { return origin; }

double Sphere::get_radius() { return radius; }

} // namespace shape