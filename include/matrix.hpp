#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <vector>

#include "tuple.hpp"

#undef minor // reserved minor is against C++ standard

namespace matrix
{
class Matrix
{
public:
    Matrix(std::initializer_list<std::initializer_list<double>> row_list);
    Matrix(int width_, int height_, std::vector<double> data_);
    Matrix(int width_, int height_);
    ~Matrix(void);

    const std::vector<double> get_data(void);
    const int get_width(void);
    const int get_height(void);

    const std::vector<double> get_row(int x);

    inline double & operator()(int x, int y) { return data[x * width + y]; };

private:
    const int width;
    const int height;
    std::vector<double> data;
};

// Equality Operations
bool is_equal_matrix(Matrix a, Matrix b);

// Matrix Operations
Matrix matrix_multiply(Matrix a, Matrix b);
tuple::Tuple tuple_multiply(Matrix m, tuple::Tuple t);
Matrix transpose(Matrix a);
double determinant(Matrix a);
Matrix submatrix(Matrix a, int row, int col);
double minor(Matrix a, int row, int col);
double cofactor(Matrix a, int row, int col);
Matrix inverse(Matrix a);
void dump_matrix(Matrix a);

// Overloaded Operators
inline bool operator==(Matrix a, Matrix b) { return is_equal_matrix(a, b); };
inline bool operator!=(Matrix a, Matrix b) { return !(is_equal_matrix(a, b)); };
inline Matrix operator*(Matrix a, Matrix b) { return matrix_multiply(a, b); };
inline tuple::Tuple operator*(Matrix m, tuple::Tuple t) { return tuple_multiply(m, t); };

} // namespace matrix

#endif // MATRIX_HPP_
