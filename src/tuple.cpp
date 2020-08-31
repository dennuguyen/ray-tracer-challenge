#include <cassert>
#include <iostream>

#include "tuple.hpp"
#include "utils.hpp"

namespace tuple
{
Tuple::Tuple(double x_, double y_, double z_, bool w_)
    : x(x_)
    , y(y_)
    , z(z_)
    , w(w_)
{}

Tuple::~Tuple(void) {}

Tuple make_point(double x_, double y_, double z_)
{
    return Tuple(x_, y_, z_, 1.0);
}

Tuple make_vector(double x_, double y_, double z_)
{
    return Tuple(x_, y_, z_, 0.0);
}

bool is_equal_tuple(Tuple a, Tuple b)
{
    if (d_cmp(a.x, b.x, EPSILON) &&
        d_cmp(a.y, b.y, EPSILON) &&
        d_cmp(a.z, b.z, EPSILON) &&
        d_cmp(a.w, b.w, EPSILON))
    {
        return true;
    }
    
    return false;
}

Tuple add(Tuple a, Tuple b)
{
    // Addition of points does not make sense
    assert(a.w + b.w != 2);

    return Tuple(a.x + b.x,
                 a.y + b.y,
                 a.z + b.z,
                 a.w + b.w);
}

Tuple minus(Tuple a, Tuple b)
{
    // Subtraction of point from vector does not make sense
    assert(a.w - b.w != -1);

    return Tuple(a.x - b.x,
                 a.y - b.y,
                 a.z - b.z,
                 a.w - b.w);
}

// Function accounts for negation of zero vector
Tuple negate(Tuple a)
{
    return Tuple(-a.x,
                 -a.y,
                 -a.z,
                 a.w);
}

Tuple scalar_multiply(Tuple a, double scalar)
{
    return Tuple(scalar * a.x,
                 scalar * a.y,
                 scalar * a.z,
                 a.w);
}

Tuple scalar_divide(Tuple a, double scalar)
{
    return Tuple(a.x / scalar,
                 a.y / scalar,
                 a.z / scalar,
                 a.w);
}

double magnitude(Tuple u)
{
    return sqrt(pow(u.x, 2) + pow(u.y, 2) + pow(u.z, 2));
}

Tuple normalise(Tuple u)
{
    // Does not make sense to normalise a point
    assert(u.w == IS_VECTOR);

    return Tuple(u.x / magnitude(u),
                 u.y / magnitude(u),
                 u.z / magnitude(u),
                 IS_VECTOR);
}

double dot(Tuple a, Tuple b)
{
    // Does not make sense to dot points
    assert(a.w == IS_VECTOR);
    assert(b.w == IS_VECTOR);

    return a.x * b.x +
           a.y * b.y +
           a.z * b.z;
}

Tuple cross(Tuple a, Tuple b)
{
    // Does not make sense to cross points
    assert(a.w == IS_VECTOR);
    assert(b.w == IS_VECTOR);

    return Tuple(a.y * b.z - a.z * b.y,
                 a.z * b.x - a.x * b.z,
                 a.x * b.y - a.y * b.x,
                 IS_VECTOR);
}

void dump(Tuple a)
{
    std::cout << std::endl;
    std::cout << a.x << " ";
    std::cout << a.y << " ";
    std::cout << a.z << " ";
    std::cout << a.w << " ";
    std::cout << std::endl;
}

} // namespace tuple
