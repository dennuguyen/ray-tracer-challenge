#include <cassert>
#include <cmath>
#include <iostream>

#include "matrix.hpp"

namespace matrix
{
Matrix::Matrix(void) : Matrix(4, 4) {}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> row_list)
    : width(row_list.size())
    , height(row_list.begin()->size())
{
    data.reserve(width * height);

    for (auto const & row : row_list)
        data.insert(data.cend(), row);
}

Matrix::Matrix(int width_, int height_, std::vector<double> data_)
    : width(width_)
    , height(height_)
    , data(data_)
{}

Matrix::Matrix(int width_, int height_)
    : width(width_)
    , height(height_)
{
    data.resize(width * height);

    for (int i = 0; i < width; i++)
        data[i * width + i] = 1.0;
}

Matrix::~Matrix(void) {}

const std::vector<double> Matrix::get_data(void) { return data; }
const int Matrix::get_width(void) { return width; }
const int Matrix::get_height(void) { return height; }

const std::vector<double> Matrix::get_row(int x)
{
    std::vector<double>::const_iterator start = data.begin() + x * width;
    std::vector<double>::const_iterator end = data.begin() + (x + 1) * width;
    std::vector<double> row(start, end);

    return row;
}

bool is_equal_matrix(Matrix a, Matrix b)
{
    if (a.get_width() != b.get_width() || a.get_height() != b.get_height())
        return false;

    for (int i = 0; i < a.get_width(); i++)
        for (int j = 0; j < a.get_height(); j++)
            if (a(i, j) != b(i, j))
                return false;

    return true;
}

Matrix matrix_multiply(Matrix a, Matrix b)
{
    assert(a.get_width() == b.get_height());

    Matrix m(a.get_width(), a.get_height());

    for (int i = 0; i < a.get_width(); i++)
        for (int j = 0; j < b.get_height(); j++)
            m(i, j) = a(i, 0) * b(0, j) +
                      a(i, 1) * b(1, j) +
                      a(i, 2) * b(2, j) +
                      a(i, 3) * b(3, j);

    return m;
}

tuple::Tuple tuple_multiply(Matrix m, tuple::Tuple t)
{
    assert(m.get_width() == 4);

    double x, y, z, w;

    x = m(0, 0) * t.x + m(0, 1) * t.y + m(0, 2) * t.z + m(0, 3) * t.w;
    y = m(1, 0) * t.x + m(1, 1) * t.y + m(1, 2) * t.z + m(1, 3) * t.w;
    z = m(2, 0) * t.x + m(2, 1) * t.y + m(2, 2) * t.z + m(2, 3) * t.w;
    w = m(3, 0) * t.x + m(3, 1) * t.y + m(3, 2) * t.z + m(3, 3) * t.w;

    t.x = x;
    t.y = y;
    t.z = z;
    t.w = w;

    return t;
}

Matrix transpose(Matrix a)
{
    return Matrix
           {
               { a(0, 0), a(1, 0), a(2, 0), a(3, 0) },
               { a(0, 1), a(1, 1), a(2, 1), a(3, 1) },
               { a(0, 2), a(1, 2), a(2, 2), a(3, 2) },
               { a(0, 3), a(1, 3), a(2, 3), a(3, 3) },
           };
}

double determinant(Matrix a)
{
    if (a.get_width() == 2 && a.get_height() == 2)
        return a(0, 0) * a(1, 1) - a(0, 1) * a(1, 0);

    double det = 0;

    for (int i = 0; i < a.get_width(); i++)
        det += a(0, i) * cofactor(a, 0, i);

    return det;
}

Matrix submatrix(Matrix a, int row, int col)
{
    std::vector<double> data;

    for (int i = 0; i < a.get_width(); i++)
        for (int j = 0; j < a.get_height(); j++)
            if (i != row && j != col)
                data.push_back(a(i, j));

    return Matrix(a.get_width() - 1, a.get_height() - 1, data);
}

double minor(Matrix a, int row, int col)
{
    return determinant(submatrix(a, row, col));
}

double cofactor(Matrix a, int row, int col)
{
    if ((row + col) % 2 == 0)
        return minor(a, row, col);
    
    return -minor(a, row, col);
}

Matrix inverse(Matrix a)
{
    assert(determinant(a) != 0);

    Matrix b(a.get_width(), a.get_height());
    
    for (int i = 0; i < a.get_width(); i++)
        for (int j = 0; j < a.get_height(); j++)
            b(j, i) = cofactor(a, i, j) / determinant(a);

    return b;
}

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

void dump_matrix(Matrix a)
{
    std::cout << std::endl;

    for (int i = 0; i < a.get_width(); i++)
    {
        for (int j = 0; j < a.get_height(); j++)
            std::cout << a(i, j) << " ";

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

} // namespace matrix
