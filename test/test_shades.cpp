#include <cassert>
#include <cmath>
#include <iostream>

#include "ray.hpp"
#include "shape.hpp"
#include "sphere.hpp"

#include "test_shades.hpp"
#include "utils.hpp"

void test_shades(void)
{
    test_sphere_normal();
    test_transformed_sphere_normal();
    test_reflect();
}

void test_sphere_normal(void)
{
    std::cout << "Testing normal vector of sphere" << std::endl;

    shape::Sphere s;
    tuple::Tuple n1 = s.normal(tuple::make_point(1, 0, 0));
    tuple::Tuple n2 = s.normal(tuple::make_point(0, 1, 0));
    tuple::Tuple n3 = s.normal(tuple::make_point(0, 0, 1));
    tuple::Tuple n4 = s.normal(tuple::make_point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));

    assert (n1 == tuple::make_vector(1, 0, 0));
    assert (n2 == tuple::make_vector(0, 1, 0));
    assert (n3 == tuple::make_vector(0, 0, 1));
    assert (n4 == tuple::make_vector(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
    assert (n4 == tuple::normalise(n4));

    std::cout << "Passed!" << std::endl;
}

void test_transformed_sphere_normal(void)
{
    std::cout << "Testing normal vector of transformed sphere" << std::endl;

    shape::Sphere s;

    s.set_transform(matrix::translate(0, 1, 0));
    tuple::Tuple n1 = s.normal(tuple::make_point(0, 1.70711, -0.70711));

    assert (n1 == tuple::make_vector(0, 0.707107, -0.707107));

    s.set_transform(matrix::scale(1, 0.5, 1) * matrix::rotate_z(M_PI / 5));
    tuple::Tuple n2 = s.normal(tuple::make_point(0, sqrt(2) / 2, sqrt(2) / 2));

    assert(n2 == tuple::make_vector(0, 0.97014, 0.24254)); // -0.24254?

    std::cout << "Passed!" << std::endl;
}

void test_reflect(void)
{
    std::cout << "Testing reflection vector" << std::endl;

    shape::Sphere s;

    tuple::Tuple v1 = tuple::make_vector(1, -1, 0);
    tuple::Tuple n1 = tuple::make_vector(0, 1, 0);

    tuple::Tuple r1 = tuple::reflect(v1, n1);

    assert(r1 == tuple::make_vector(1, 1, 0));

    tuple::Tuple v2 = tuple::make_vector(0, -1, 0);
    tuple::Tuple n2 = tuple::make_vector(sqrt(2) / 2, sqrt(2) / 2, 0);

    tuple::Tuple r2 = tuple::reflect(v2, n2);

    assert(r2 == tuple::make_vector(1, 0, 0));

    std::cout << "Passed!" << std::endl;
}
