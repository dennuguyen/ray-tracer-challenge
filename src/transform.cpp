#include <cmath>

#include "transform.hpp"

namespace matrix
{
Matrix translate(double x, double y, double z)
{
    Matrix m(4, 4);

    m(0, 3) = x;
    m(1, 3) = y;
    m(2, 3) = z;

    return m;
}

Matrix scale(double x, double y, double z)
{
    Matrix m(4, 4);

    m(0, 0) = x;
    m(1, 1) = y;
    m(2, 2) = z;

    return m;
}

Matrix rotate_x(double r)
{
    Matrix m(4, 4);

    m(1, 1) = cos(r);
    m(1, 2) = -sin(r);
    m(2, 1) = sin(r);
    m(2, 2) = cos(r);

    return m;
}

Matrix rotate_y(double r)
{
    Matrix m(4, 4);

    m(0, 0) = cos(r);
    m(0, 2) = sin(r);
    m(2, 0) = -sin(r);
    m(2, 2) = cos(r);

    return m;
}

Matrix rotate_z(double r)
{
    Matrix m(4, 4);

    m(0, 0) = cos(r);
    m(0, 1) = -sin(r);
    m(1, 0) = sin(r);
    m(1, 1) = cos(r);

    return m;
}

Matrix shear(double x_y, double x_z, double y_x, double y_z, double z_x, double z_y)
{
    Matrix m(4, 4);

    m(0, 1) = x_y;
    m(0, 2) = x_z;
    m(1, 0) = y_x;
    m(1, 2) = y_z;
    m(2, 0) = z_x;
    m(2, 1) = z_y;

    return m;
}

} // namespace matrix
