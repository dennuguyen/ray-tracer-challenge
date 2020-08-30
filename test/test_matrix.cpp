#include <cassert>
#include <iostream>

#include "matrix.hpp"
#include "test_matrix.hpp"

void test_matrix(void)
{
    test_matrix_creation();
    test_2x2_matrix();
    test_3x3_matrix();
    test_matrix_equality();
    test_matrix_multiplication();
    test_tuple_multiplication();
    test_identity_matrix();
    test_transpose();
    test_determinant();
    test_submatrix();
    test_minor();
    test_cofactor();
    test_extra_cofactor();
    test_invertibility();
    test_matrix_inverse();
    test_further_matrix_inverse();
    test_matrix_inverse_proof();
}

void test_matrix_creation(void)
{
    std::cout << "Testing matrix creation" << std::endl;

    matrix::Matrix m
    {
        { 1, 2, 3, 4 },
        { 5.5, 6.5, 7.5, 8.5 },
        { 9, 10, 11, 12 },
        { 13.5, 14.5, 15.5, 16.5 }
    };

    assert(m(0, 0) == 1);
    assert(m(0, 3) == 4);
    assert(m(1, 0) == 5.5);
    assert(m(1, 2) == 7.5);
    assert(m(2, 2) == 11);
    assert(m(3, 0) == 13.5);
    assert(m(3, 2) == 15.5);

    std::cout << "Passed!" << std::endl;
}

void test_2x2_matrix(void)
{
    std::cout << "Testing 2x2 matrix creation" << std::endl;

    matrix::Matrix m
    {
        { -3, 5 },
        { 1, -2 }
    };

    assert(m(0, 0) == -3);
    assert(m(0, 1) == 5);
    assert(m(1, 0) == 1);
    assert(m(1, 1) == -2);

    std::cout << "Passed!" << std::endl;
}

void test_3x3_matrix(void)
{
    std::cout << "Testing 3x3 matrix creation" << std::endl;

    matrix::Matrix m
    {
        { -3, 5, 0 },
        { 1, -2, -7 },
        { 0, 1, 1 }
    };

    assert(m(0, 0) == -3);
    assert(m(0, 1) == 5);
    assert(m(0, 2) == 0);
    assert(m(1, 0) == 1);
    assert(m(1, 1) == -2);
    assert(m(1, 2) == -7);
    assert(m(2, 0) == 0);
    assert(m(2, 1) == 1);
    assert(m(2, 2) == 1);

    std::cout << "Passed!" << std::endl;
}

void test_matrix_equality(void)
{
    std::cout << "Testing matrix equality" << std::endl;

    matrix::Matrix a
    {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 8, 7, 6 },
        { 5, 4, 3, 2 }
    };

    matrix::Matrix b
    {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 8, 7, 6 },
        { 5, 4, 3, 2 }
    };

    assert(a == b);

    matrix::Matrix c
    {
        { 2, 3, 4, 5 },
        { 6, 7, 8, 9 },
        { 8, 7, 6, 5 },
        { 4, 3, 2, 1 }
    };

    assert(a != c);

    std::cout << "Passed!" << std::endl;
}

void test_matrix_multiplication(void)
{
    std::cout << "Testing matrix multiplication" << std::endl;

    matrix::Matrix a
    {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 8, 7, 6 },
        { 5, 4, 3, 2 }
    };

    matrix::Matrix b
    {
        { -2, 1, 2, 3 },
        { 3, 2, 1, -1 },
        { 4, 3, 6, 5 },
        { 1, 2, 7, 8 }
    };

    matrix::Matrix c
    {
        { 20, 22, 50, 48 },
        { 44, 54, 114, 108 },
        { 40, 58, 110, 102 },
        { 16, 26, 46, 42 }
    };

    assert(c == a * b);

    std::cout << "Passed!" << std::endl;
}

void test_tuple_multiplication(void)
{
    std::cout << "Testing tuple multiplication" << std::endl;

    matrix::Matrix a
    {
        { 1, 2, 3, 4 },
        { 2, 4, 4, 2 },
        { 8, 6, 4, 1 },
        { 0, 0, 0, 1 }
    };

    tuple::Tuple b(1, 2, 3, 1);
    tuple::Tuple c(18, 24, 33, 1);

    assert(c == tuple_multiply(a, b));

    std::cout << "Passed!" << std::endl;
}

void test_identity_matrix(void)
{
    std::cout << "Testing identity matrix" << std::endl;

    matrix::Matrix a
    {
        { 0, 1, 2, 4 },
        { 1, 2, 4, 8 },
        { 2, 4, 8, 16 },
        { 4, 8, 16, 32 }
    };

    matrix::Matrix i(4, 4);
    matrix::Matrix b = a * i;

    assert(a == b);

    tuple::Tuple c(1, 2, 3, 4);
    tuple::Tuple d = tuple_multiply(i, c);

    assert (c == d);

    std::cout << "Passed!" << std::endl;
}

void test_transpose(void)
{
    std::cout << "Testing matrix transpose" << std::endl;

    matrix::Matrix a
    {
        { 0, 9, 3, 0 },
        { 9, 8, 0, 8 },
        { 1, 8, 5, 3 },
        { 0, 0, 5, 8 }
    };

    matrix::Matrix b
    {
        { 0, 9, 1, 0 },
        { 9, 8, 8, 0 },
        { 3, 0, 5, 5 },
        { 0, 8, 3, 8 }
    };

    matrix::Matrix c = transpose(a);

    assert(b == c);

    matrix::Matrix i(4, 4);
    matrix::Matrix j = transpose(i);

    assert (i == j);

    std::cout << "Passed!" << std::endl;
}

void test_determinant(void)
{
    std::cout << "Testing matrix determinant" << std::endl;

    matrix::Matrix a
    {
        { 1, 5 },
        { -3, 2 }
    };

    assert(determinant(a) == 17);

    std::cout << "Passed!" << std::endl;
}

void test_submatrix(void)
{
    std::cout << "Testing submatrix" << std::endl;

    matrix::Matrix a
    {
        { 1, 5, 0 },
        { -3, 2, 7 },
        { 0, 6, -3 }
    };

    matrix::Matrix b
    {
        { -3, 2 },
        { 0, 6 }
    };

    assert(b == submatrix(a, 0, 2));

    matrix::Matrix c
    {
        { -6, 1, 1, 6 },
        { -8, 5, 8, 6 },
        { -1, 0, 8, 2 },
        { -7, 1, -1, 1 }
    };

    matrix::Matrix d
    {
        { -6, 1, 6 },
        { -8, 8, 6 },
        { -7, -1, 1 }
    };

    assert(d == submatrix(c, 2, 1));

    std::cout << "Passed!" << std::endl;
}

void test_minor(void)
{
    std::cout << "Testing matrix minor" << std::endl;

    matrix::Matrix a
    {
        { 3, 5, 0 },
        { 2, -1, -7 },
        { 6, -1, 5 }
    };

    assert(minor(a, 1, 0) == 25);

    matrix::Matrix b = submatrix(a, 1, 0);

    assert(determinant(b) == 25);

    std::cout << "Passed!" << std::endl;
}

void test_cofactor(void)
{
    std::cout << "Testing matrix cofactor" << std::endl;

    matrix::Matrix a
    {
        { 3, 5, 0 },
        { 2, -1, -7 },
        { 6, -1, 5 }
    };

    assert(minor(a, 0, 0) == -12);
    assert(cofactor(a, 0, 0) == -12);

    assert(minor(a, 1, 0) == 25);
    assert(cofactor(a, 1, 0) == -25);

    std::cout << "Passed!" << std::endl;
}

void test_extra_cofactor(void)
{
    std::cout << "Testing 3x3 and 4x4 matrix cofactor" << std::endl;

    matrix::Matrix a
    {
        { 1, 2, 6 },
        { -5, 8, -4 },
        { 2, 6, 4 }
    };

    assert(cofactor(a, 0, 0) == 56);
    assert(cofactor(a, 0, 1) == 12);
    assert(cofactor(a, 0, 2) == -46);
    assert(determinant(a) == -196);

    matrix::Matrix b
    {
        { -2, -8, 3, 5 },
        { -3, 1, 7, 3 },
        { 1, 2, -9, 6 },
        { -6, 7, 7, -9 }
    };

    assert(cofactor(b, 0, 0) == 690);
    assert(cofactor(b, 0, 1) == 447);
    assert(cofactor(b, 0, 2) == 210);
    assert(cofactor(b, 0, 3) == 51);
    assert(determinant(b) == -4071);

    std::cout << "Passed!" << std::endl;
}

void test_invertibility(void)
{
    std::cout << "Testing matrix invertibility" << std::endl;

    matrix::Matrix a
    {
        { 6, 4, 4, 4 },
        { 5, 5, 7, 6 },
        { 4, -9, 3, -7 },
        { 9, 1, 7, -6 }
    };

    assert(determinant(a) == -2120);

    matrix::Matrix b
    {
        { -4, 2, -2, -3 },
        { 9, 6, 2, 6 },
        { 0, -5, 1, -5 },
        { 0, 0, 0, 0 }
    };

    assert(determinant(b) == 0);

    std::cout << "Passed!" << std::endl;
}

void test_matrix_inverse(void)
{
    std::cout << "Testing matrix inverse" << std::endl;

    matrix::Matrix a
    {
        { -5, 2, 6, -8 },
        { 1, -5, 1, 8 },
        { 7, 7, -6, -7 },
        { 1, -3, 7, 4 }
    };

    assert(determinant(a) == 532);
    assert(cofactor(a, 2, 3) == -160);
    assert(cofactor(a, 3, 2) == 105);

    matrix::Matrix b = inverse(a);

    // dump_matrix(b);

    matrix::Matrix b_ans
    {
        { 0.21805, 0.45113, 0.24060, -0.04511 },
        { -0.80827, -1.45677, -0.44361, 0.52068 },
        { -0.07895, -0.22368, -0.05263, 0.19737 },
        { -0.52256, -0.81391, -0.30075, 0.30639 }
    };

    std::cout << "Passed!" << std::endl;
}

void test_further_matrix_inverse(void)
{
    std::cout << "Testing further matrix inverse" << std::endl;

    matrix::Matrix a
    {
        { 8, -5, 9, 2 },
        { 7, 5, 6, 1 },
        { -6, 0, 9, 6 },
        { -3, 0, -9, -4 }
    };
    
    matrix::Matrix b = inverse(a);

    // dump_matrix(b);

    matrix::Matrix b_ans
    {
        { -0.15385, -0.15385, -0.28205, -0.53846 },
        { -0.07692, 0.12308, 0.02564, 0.03077 },
        { 0.35897, 0.35897, 0.42590, 0.92308 },
        { -0.69231, -0.69231, -0.76923, -1.92308 }
    };

    matrix::Matrix c
    {
        { 9, 3, 0, 9 },
        { -5, -2, -6, -3 },
        { -4, 9, 6, 4 },
        { -7, 6, 6, 2 }
    };
    
    matrix::Matrix d = inverse(c);

    // dump_matrix(d);

    matrix::Matrix d_ans
    {
        { -0.04074, -0.07778, 0.14444, -0.22222 },
        { -0.07778, 0.03333, 0.36667, -0.33333 },
        { -0.02901, -0.14630, -0.10926, 0.12963 },
        { 0.17778, 0.06667, -0.26667, 0.33333 }
    };

    std::cout << "Passed!" << std::endl;
}

void test_matrix_inverse_proof(void)
{
    std::cout << "Testing matrix inverse proof" << std::endl;

    matrix::Matrix a
    {
        { 3, -9, 7, 3 },
        { 3, -8, 2, -9 },
        { -4, 4, 4, 1 },
        { -6, 5, -1, 1 }
    };

    matrix::Matrix b
    {
        { 8, 2, 2, 2 },
        { 3, -1, 7, 0 },
        { 7, 0, 5, 4 },
        { 6, -2, 0, 5 }
    };

    matrix::Matrix c = a * b;

    dump_matrix(c * inverse(b));
    dump_matrix(a);

    std::cout << "Passed!" << std::endl;
}