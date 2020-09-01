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

bool is_same_colour(Colour a, Colour b);
inline bool operator==(Colour a, Colour b) { return is_same_colour(a, b); };

Colour add(Colour a, Colour b);
Colour minus(Colour a, Colour b);
Colour scalar_multiply(Colour a, double scalar);
Colour colour_multiply(Colour a, Colour b);

const Colour NONE(NOFILL, NOFILL, NOFILL);
const Colour BLACK(0.0, 0.0, 0.0);
const Colour WHITE(1.0, 1.0, 1.0);
const Colour RED(1.0, 0.0, 0.0);
const Colour GREEN(0.0, 1.0, 0.0);
const Colour BLUE(0.0, 0.0, 1.0);
}  // namespace colour

#endif  // COLOUR_HPP_
