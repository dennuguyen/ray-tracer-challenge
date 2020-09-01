#include <cassert>
#include <cmath>
#include <iostream>

#include "environment.hpp"
#include "projectile.hpp"
#include "test_tuple.hpp"
#include "tuple.hpp"
#include "utils.hpp"

void test_tuple(void)
{
    test_tuple_point();
    test_tuple_vector();
    test_is_equal_value();
    test_is_equal_tuple();
    test_add();
    test_minus_point();
    test_minus_vector_point();
    test_minus_vector();
    test_negate();
    test_scalar_multiply();
    test_scalar_divide();
    test_magnitude();
    test_normalise();
    test_dot_product();
    test_cross_product();
}

void test_tuple_point(void)
{
    std::cout << "Testing tuple point" << std::endl;

    tuple::Tuple point = tuple::make_point(4.3, -4.2, 3.1);

    assert(point.x == 4.3);
    assert(point.y == -4.2);
    assert(point.z == 3.1);
    assert(point.w == 1.0);

    std::cout << "Passed!" << std::endl;
}

void test_tuple_vector(void)
{
    std::cout << "Testing tuple vector" << std::endl;

    tuple::Tuple vector = tuple::make_vector(4.3, -4.2, 3.1);

    assert(vector.x == 4.3);
    assert(vector.y == -4.2);
    assert(vector.z == 3.1);
    assert(vector.w == 0.0);

    std::cout << "Passed!" << std::endl;
}

void test_is_equal_value(void)
{
    std::cout << "Testing equality of values" << std::endl;

    assert(d_cmp(1, 1 - tuple::EPSILON, tuple::EPSILON));

    std::cout << "Passed!" << std::endl;
}

void test_is_equal_tuple(void)
{
    std::cout << "Testing equality of tuples" << std::endl;

    tuple::Tuple a1(4.3, -4.2, 3.1, 1.0);
    tuple::Tuple a2(4.3 + tuple::EPSILON, -4.2 - tuple::EPSILON, 3.1 - tuple::EPSILON, 1.0);

    assert(tuple::is_equal_tuple(a1, a2));

    std::cout << "Passed!" << std::endl;
}

void test_add(void)
{
    std::cout << "Testing addition of tuples" << std::endl;

    tuple::Tuple a1(3, -2, 5, 1);
    tuple::Tuple a2(-2, 3, 1, 0);
    tuple::Tuple a3 = add(a1, a2);

    assert(a3.x == 1);
    assert(a3.y == 1);
    assert(a3.z == 6);
    assert(a3.w == 1);

    std::cout << "Passed!" << std::endl;
}

void test_minus_point(void)
{
    std::cout << "Testing subtraction of points" << std::endl;

    tuple::Tuple p1 = tuple::make_point(3, 2, 1);
    tuple::Tuple p2 = tuple::make_point(5, 6, 7);
    tuple::Tuple a1 = minus(p1, p2);

    assert(a1.x == -2);
    assert(a1.y == -4);
    assert(a1.z == -6);
    assert(a1.w == 0);

    std::cout << "Passed!" << std::endl;
}

void test_minus_vector_point(void)
{
    std::cout << "Testing subtraction of vector from point" << std::endl;

    tuple::Tuple p = tuple::make_point(3, 2, 1);
    tuple::Tuple v = tuple::make_vector(5, 6, 7);
    tuple::Tuple a1 = minus(p, v);

    assert(a1.x == -2);
    assert(a1.y == -4);
    assert(a1.z == -6);
    assert(a1.w == 1);

    std::cout << "Passed!" << std::endl;
}

void test_minus_vector(void)
{
    std::cout << "Testing subtraction of vectors" << std::endl;

    tuple::Tuple v1 = tuple::make_vector(3, 2, 1);
    tuple::Tuple v2 = tuple::make_vector(5, 6, 7);
    tuple::Tuple v3 = minus(v1, v2);

    assert(v3.x == -2);
    assert(v3.y == -4);
    assert(v3.z == -6);
    assert(v3.w == 0);

    std::cout << "Passed!" << std::endl;
}

void test_minus_zero_vector(void)
{
    std::cout << "Testing subtraction of vector from zero vector" << std::endl;

    tuple::Tuple v1 = tuple::make_vector(0, 0, 0);
    tuple::Tuple v2 = tuple::make_vector(1, -2, 3);
    tuple::Tuple v3 = minus(v1, v2);

    assert(v3.x == -1);
    assert(v3.y == 2);
    assert(v3.z == -3);
    assert(v3.w == 0);

    std::cout << "Passed!" << std::endl;
}

void test_negate(void)
{
    std::cout << "Testing negation of tuple" << std::endl;

    tuple::Tuple a(1, -2, 3, 1);
    tuple::Tuple b = negate(a);

    assert(b.x == -1);
    assert(b.y == 2);
    assert(b.z == -3);
    assert(b.w == 1);

    std::cout << "Passed!" << std::endl;
}

void test_scalar_multiply(void)
{
    std::cout << "Testing scalar multiplication of tuple" << std::endl;

    tuple::Tuple a(1, -2, 3, 1);
    tuple::Tuple b = scalar_multiply(a, 3.5);

    assert(b.x == 3.5);
    assert(b.y == -7);
    assert(b.z == 10.5);
    assert(b.w == 1);

    tuple::Tuple c(1, -2, 3, 1);
    tuple::Tuple d = scalar_multiply(c, 0.5);

    assert(d.x == 0.5);
    assert(d.y == -1);
    assert(d.z == 1.5);
    assert(d.w == 1);

    std::cout << "Passed!" << std::endl;
}

void test_scalar_divide(void)
{
    std::cout << "Testing scalar division of tuple" << std::endl;

    tuple::Tuple a(1, -2, 3, 1);
    tuple::Tuple b = scalar_divide(a, 2);

    assert(b.x == 0.5);
    assert(b.y == -1);
    assert(b.z == 1.5);
    assert(b.w == 1);

    std::cout << "Passed!" << std::endl;
}

void test_magnitude(void)
{
    std::cout << "Testing modulus of tuple" << std::endl;

    tuple::Tuple v1 = tuple::make_vector(1, 0, 0);
    tuple::Tuple v2 = tuple::make_vector(0, 1, 0);
    tuple::Tuple v3 = tuple::make_vector(0, 0, 1);
    tuple::Tuple v4 = tuple::make_vector(1, 2, 3);
    tuple::Tuple v5 = tuple::make_vector(-1, -2, -3);

    assert(magnitude(v1) == 1);
    assert(magnitude(v2) == 1);
    assert(magnitude(v3) == 1);
    assert(magnitude(v4) == sqrt(14));
    assert(magnitude(v5) == sqrt(14));

    std::cout << "Passed!" << std::endl;
}

void test_normalise(void)
{
    std::cout << "Testing normalisation of tuple" << std::endl;

    tuple::Tuple u1 = tuple::make_vector(4, 0, 0);
    tuple::Tuple v1 = normalise(u1);

    assert(v1.x == 1);
    assert(v1.y == 0);
    assert(v1.z == 0);
    assert(v1.w == 0);

    tuple::Tuple u2 = tuple::make_vector(1, 2, 3);
    tuple::Tuple v2 = normalise(u2);

    assert(v2.x == 1/sqrt(14));
    assert(v2.y == 2/sqrt(14));
    assert(v2.z == 3/sqrt(14));
    assert(v2.w == 0);

    assert(magnitude(v2) == 1);

    std::cout << "Passed!" << std::endl;
}

void test_dot_product(void)
{
    std::cout << "Testing dot product of two vectors" << std::endl;

    tuple::Tuple a = tuple::make_vector(1, 2, 3);
    tuple::Tuple b = tuple::make_vector(2, 3, 4);

    assert(dot(a, b) == 20);

    std::cout << "Passed!" << std::endl;
}

void test_cross_product(void)
{
    std::cout << "Testing cross product of two vectors" << std::endl;

    tuple::Tuple a = tuple::make_vector(1, 2, 3);
    tuple::Tuple b = tuple::make_vector(2, 3, 4);
    tuple::Tuple c = cross(a, b);
    tuple::Tuple d = cross(b, a);

    assert(c.x == -1);
    assert(c.y == 2);
    assert(c.z == -1);

    assert(d.x == 1);
    assert(d.y == -2);
    assert(d.z == 1);

    std::cout << "Passed!" << std::endl;
}
