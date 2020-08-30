#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include "matrix.hpp"

namespace matrix
{
Matrix translate(double x, double y, double z);
Matrix scale(double x, double y, double z);
Matrix rotate_x(double r);
Matrix rotate_y(double r);
Matrix rotate_z(double r);
Matrix shear(double x_y, double x_z, double y_x, double y_z, double z_x, double z_y);
} // namespace matrix

#endif // TRANSFORM_HPP_
