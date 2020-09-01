#ifndef TUPLE_HPP_
#define TUPLE_HPP_

#include <limits>

namespace tuple
{
const double IS_POINT = 1.0;
const double IS_VECTOR = 0.0;
const double EPSILON = 1e2 * std::numeric_limits<double>::epsilon();

struct Tuple
{
public:
    Tuple(double x_, double y_, double z_, bool w_);
    ~Tuple(void);

    double x;
    double y;
    double z;
    bool w; // 1 for points, 0 for vectors
};

// Point & Vector Factory
Tuple make_point(double x_, double y_, double z_);
Tuple make_point(Tuple u);
Tuple make_vector(double x_, double y_, double z_);
Tuple make_vector(Tuple u);

// Equality Operations
bool is_equal_tuple(Tuple a, Tuple b);

// Tuple Operations
Tuple add(Tuple a, Tuple b);
Tuple minus(Tuple a, Tuple b);
Tuple negate(Tuple a);
Tuple scalar_multiply(Tuple a, double scalar);
Tuple scalar_divide(Tuple a, double scalar);

// Vector-specific Operations
double magnitude(Tuple u);
Tuple normalise(Tuple u);
double dot(Tuple a, Tuple b);
Tuple cross(Tuple a, Tuple b);

// Overloaded Operators
inline bool operator==(Tuple a, Tuple b) { return is_equal_tuple(a, b); };
inline Tuple operator+(Tuple a, Tuple b) { return add(a, b); };
inline Tuple operator-(Tuple a, Tuple b) { return minus(a, b); };
inline Tuple operator-(Tuple a) { return negate(a); };
inline Tuple operator*(Tuple a, double scalar) { return scalar_multiply(a, scalar); };
inline Tuple operator/(Tuple a, double scalar) { return scalar_divide(a, scalar); };

// Debugging
void dump(Tuple a);

} // namespace tuple

#endif // TUPLE_HPP_
