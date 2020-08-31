#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <cmath>

#define uint unsigned int

inline bool d_cmp(double a, double b, double eps) { return std::abs(a - b) <= ((std::abs(a) < std::abs(b) ? std::abs(b) : std::abs(a)) * eps); }

#endif  // UTILS_HPP_