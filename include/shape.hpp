#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include <vector>

#include "tuple.hpp"

namespace shape
{
class Shape
{
public:
    Shape(void);

protected:
    int id;
};

class Sphere : public Shape
{
public:
    Sphere(void);
    Sphere(tuple::Tuple origin_, double radius_);

private:
    tuple::Tuple origin;
    double radius;
};

} // namespace shape

#endif // SHAPE_HPP_
