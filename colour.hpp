#ifndef COLOUR_HPP_
#define COLOUR_HPP_

#define NOFILL -1.0

namespace colour {
struct Colour {
    Colour(double r_, double g_, double b_);
    ~Colour();

    inline bool operator==(Colour col) { return (r == col.r && g == col.g && b == col.b); };

    double r;
    double g;
    double b;
};

const Colour NONE(NOFILL, NOFILL, NOFILL);
const Colour BLACK(0.0, 0.0, 0.0);
const Colour WHITE(1.0, 1.0, 1.0);
const Colour RED(1.0, 0.0, 0.0);
const Colour GREEN(0.0, 1.0, 0.0);
const Colour BLUE(0.0, 0.0, 1.0);
}  // namespace colour

#endif  // COLOUR_HPP_
