#include <iostream>
#include <cassert>
#include <cmath>

#include "matrix.hpp"
#include "test_transform.hpp"
#include "transform.hpp"

void test_transform(void)
{
    test_translation();
    test_reverse_translation();
    test_vector_translation();
    test_point_scaling();
    test_vector_scaling();
    test_reverse_scaling();
    test_reflection();
    test_rotate_x();
    test_rotate_y();
    test_rotate_z();
    test_shear();
    test_chain_transforms();
}

void test_translation(void)
{
    std::cout << "Testing translation" << std::endl;

    tuple::Tuple p1 = tuple::make_point(-3, 4, 5);
    tuple::Tuple p2 = tuple::make_point(2, 1, 7);

    assert(matrix::translate(5, -3, 2) * p1 == p2);

    std::cout << "Passed!" << std::endl;
}

void test_reverse_translation(void)
{
    std::cout << "Testing reverse translation" << std::endl;

    tuple::Tuple p1 = tuple::make_point(-3, 4, 5);
    tuple::Tuple p2 = tuple::make_point(-8, 7, 3);

    assert(inverse(matrix::translate(5, -3, 2)) * p1 == p2);

    std::cout << "Passed!" << std::endl;
}

void test_vector_translation(void)
{
    std::cout << "Testing vector translation" << std::endl;

    tuple::Tuple v = tuple::make_vector(-3, 4, 5);

    assert(matrix::translate(5, -3, 2) * v == v);

    std::cout << "Passed!" << std::endl;
}

void test_point_scaling(void)
{
    std::cout << "Testing point scaling" << std::endl;

    tuple::Tuple p1 = tuple::make_point(-4, 6, 8);
    tuple::Tuple p2 = tuple::make_point(-8, 18, 32);

    assert(matrix::scale(2, 3, 4) * p1 == p2);

    std::cout << "Passed!" << std::endl;
}

void test_vector_scaling(void)
{
    std::cout << "Testing vector scaling" << std::endl;

    tuple::Tuple v1 = tuple::make_vector(-4, 6, 8);
    tuple::Tuple v2 = tuple::make_vector(-8, 18, 32);

    assert(matrix::scale(2, 3, 4) * v1 == v2);

    std::cout << "Passed!" << std::endl;
}

void test_reverse_scaling(void)
{
    std::cout << "Testing reverse scaling" << std::endl;

    tuple::Tuple v1 = tuple::make_vector(-4, 6, 8);
    tuple::Tuple v2 = tuple::make_vector(-2, 2, 2);

    assert(inverse(matrix::scale(2, 3, 4)) * v1 == v2);

    std::cout << "Passed!" << std::endl;
}

void test_reflection(void)
{
    std::cout << "Testing reflection" << std::endl;

    tuple::Tuple v1 = tuple::make_vector(2, 3, 4);
    tuple::Tuple v2 = tuple::make_vector(-2, 3, 4);

    assert(matrix::scale(-1, 1, 1) * v1 == v2);

    std::cout << "Passed!" << std::endl;
}

void test_rotate_x(void)
{
    std::cout << "Testing rotation around x axis" << std::endl;

    tuple::Tuple p1 = tuple::make_point(0, 1, 0);
    tuple::Tuple p2 = tuple::make_point(0, sqrt(2) / 2, sqrt(2) / 2);
    tuple::Tuple p3 = tuple::make_point(0, 0, 1);

    assert(matrix::rotate_x(M_PI / 4) * p1 == p2);
    assert(matrix::rotate_x(M_PI / 2) * p1 == p3);

    tuple::Tuple p4 = tuple::make_point(0, sqrt(2) / 2, -sqrt(2) / 2);

    assert(inverse(matrix::rotate_x(M_PI / 4)) * p1 == p4);

    std::cout << "Passed!" << std::endl;
}

void test_rotate_y(void)
{
    std::cout << "Testing rotation around y axis" << std::endl;

    tuple::Tuple p1 = tuple::make_point(0, 0, 1);
    tuple::Tuple p2 = tuple::make_point(sqrt(2) / 2, 0, sqrt(2) / 2);
    tuple::Tuple p3 = tuple::make_point(1, 0, 0);

    assert(matrix::rotate_y(M_PI / 4) * p1 == p2);
    assert(matrix::rotate_y(M_PI / 2) * p1 == p3);

    std::cout << "Passed!" << std::endl;
}

void test_rotate_z(void)
{
    std::cout << "Testing rotation around z axis" << std::endl;

    tuple::Tuple p1 = tuple::make_point(0, 1, 0);
    tuple::Tuple p2 = tuple::make_point(-sqrt(2) / 2, sqrt(2) / 2, 0);
    tuple::Tuple p3 = tuple::make_point(-1, 0, 0);

    assert(matrix::rotate_z(M_PI / 4) * p1 == p2);
    assert(matrix::rotate_z(M_PI / 2) * p1 == p3);

    std::cout << "Passed!" << std::endl;
}

void test_shear(void)
{
    std::cout << "Testing shear" << std::endl;

    tuple::Tuple p1 = tuple::make_point(2, 3, 4);
    tuple::Tuple p2 = tuple::make_point(5, 3, 4);

    assert(matrix::shear(1, 0, 0, 0, 0, 0) * p1 == p2);

    tuple::Tuple p3 = tuple::make_point(2, 3, 4);
    tuple::Tuple p4 = tuple::make_point(6, 3, 4);

    assert(matrix::shear(0, 1, 0, 0, 0, 0) * p3 == p4);

    tuple::Tuple p5 = tuple::make_point(2, 3, 4);
    tuple::Tuple p6 = tuple::make_point(2, 5, 4);

    assert(matrix::shear(0, 0, 1, 0, 0, 0) * p5 == p6);

    tuple::Tuple p7 = tuple::make_point(2, 3, 4);
    tuple::Tuple p8 = tuple::make_point(2, 7, 4);

    assert(matrix::shear(0, 0, 0, 1, 0, 0) * p7 == p8);

    tuple::Tuple p9 = tuple::make_point(2, 3, 4);
    tuple::Tuple p10 = tuple::make_point(2, 3, 6);

    assert(matrix::shear(0, 0, 0, 0, 1, 0) * p9 == p10);

    tuple::Tuple p11 = tuple::make_point(2, 3, 4);
    tuple::Tuple p12 = tuple::make_point(2, 3, 7);

    assert(matrix::shear(0, 0, 0, 0, 0, 1) * p11 == p12);

    std::cout << "Passed!" << std::endl;
}

void test_chain_transforms(void)
{
    std::cout << "Testing chained transformations" << std::endl;

    tuple::Tuple p1 = tuple::make_point(1, 0, 1);
    matrix::Matrix A = matrix::rotate_x(M_PI / 2);
    matrix::Matrix B = matrix::scale(5, 5, 5);
    matrix::Matrix C = matrix::translate(10, 5, 7);

    tuple::Tuple p2 = A * p1;
    assert(p2 == tuple::Tuple(1, -1, 0, 1));

    tuple::Tuple p3 = B * p2;
    assert(p3 == tuple::Tuple(5, -5, 0, 1));

    tuple::Tuple p4 = C * p3;
    assert(p4 == tuple::Tuple(15, 0, 7, 1));

    tuple::Tuple q = C * B * A * p1;
    assert(q == tuple::Tuple(15, 0, 7, 1));

    std::cout << "Passed!" << std::endl;
}