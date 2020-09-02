#ifndef COLOUR_HPP_
#define COLOUR_HPP_

#include <limits>

namespace colour
{
const double NOFILL = -1.0;
const double EPSILON = 1e12 * std::numeric_limits<double>::epsilon();

struct Colour {
    Colour(double r_, double g_, double b_);
    ~Colour();

    double r;
    double g;
    double b;
};

// Equality Operator
bool is_same_colour(Colour a, Colour b);

// Colour Operators
Colour add(Colour a, Colour b);
Colour minus(Colour a, Colour b);
Colour scalar_multiply(Colour a, double scalar);
Colour colour_multiply(Colour a, Colour b);

// Overloaded Operators
inline bool operator==(Colour a, Colour b) { return is_same_colour(a, b); };
inline Colour operator+(Colour a, Colour b) { return add(a, b); };
inline Colour operator-(Colour a, Colour b) { return minus(a, b); };
inline Colour operator^(Colour a, double scalar) { return scalar_multiply(a, scalar); };
inline Colour operator*(Colour a, Colour b) { return colour_multiply(a, b); };

// Colour Palette
const Colour NONE(NOFILL, NOFILL, NOFILL);
const Colour BLACK(0.0, 0.0, 0.0);
const Colour WHITE(1.0, 1.0, 1.0);
const Colour RED(1.0, 0.0, 0.0);
const Colour GREEN(0.0, 1.0, 0.0);
const Colour BLUE(0.0, 0.0, 1.0);

}  // namespace colour

#endif  // COLOUR_HPP_
