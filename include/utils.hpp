#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <cmath>

#define uint unsigned int

inline bool d_cmp(double a, double b, double eps)
{
    return std::abs(a - b) <= eps ||
        std::abs(a - b) < (std::fmax(std::abs(a), std::abs(b)) * eps);
}

#endif  // UTILS_HPP_