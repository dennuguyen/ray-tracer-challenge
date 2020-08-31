#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include <vector>

#include "ray.hpp"
#include "tuple.hpp"

namespace shape
{
class Shape
{
public:
    Shape(void);
    int get_id();

protected:
    bool empty;
    int id;
};

class Sphere : public Shape
{
    public:
    Sphere(void);
    Sphere(tuple::Tuple origin_, double radius_);
    ~Sphere();

    tuple::Tuple get_origin();
    double get_radius();

    private:
    tuple::Tuple origin;
    double radius;
};

bool is_same_shape_object(Shape a, Shape b);
inline bool operator==(Shape a, Shape b) { return is_same_shape_object(a, b); };

} // namespace shape

#endif // SHAPE_HPP_
