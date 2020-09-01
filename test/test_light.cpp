#include <cassert>
#include <cmath>
#include <iostream>

#include "ray.hpp"
#include "shape.hpp"
#include "sphere.hpp"

#include "test_light.hpp"

void test_light(void)
{
    test_sphere_normal();
}

void test_sphere_normal(void)
{
    std::cout << "Testing normal of sphere" << std::endl;

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
