#include "colour.hpp"
#include "utils.hpp"

namespace colour {
Colour::Colour(double r_, double g_, double b_)
    : r(r_), g(g_), b(b_) {
}

Colour::~Colour() {}

bool is_same_colour(Colour a, Colour b)
{
    return d_cmp(a.r, b.r, EPSILON)
        && d_cmp(a.g, b.g, EPSILON)
        && d_cmp(a.b, b.b, EPSILON);
}

Colour add(Colour a, Colour b)
{
    return Colour(a.r + b.r,
                  a.g + b.g,
                  a.b + b.b);
}

Colour minus(Colour a, Colour b)
{
    return Colour(a.r - b.r,
                  a.g - b.g,
                  a.b - b.b);
}

Colour scalar_multiply(Colour a, double scalar)
{
    return Colour(scalar * a.r,
                  scalar * a.g,
                  scalar * a.b);
}

Colour colour_multiply(Colour a, Colour b)
{
    return Colour(a.r * b.r,
                  a.g * b.g,
                  a.b * b.b);
}

}  // namespace colour
