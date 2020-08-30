#include <iostream>
#include <cassert>

#include "matrix.hpp"
#include "ray.hpp"
#include "shape.hpp"
#include "test_ray.hpp"

void test_ray(void)
{
    test_ray_creation();
    test_point_on_ray();
    test_sphere_ray_intersection();
}

void test_ray_creation(void)
{
    std::cout << "Testing ray creation" << std::endl;

    tuple::Tuple origin = tuple::make_point(1, 2, 3);
    tuple::Tuple direction = tuple::make_vector(4, 5, 6);

    ray::Ray r(origin, direction);

    assert(r.origin == origin);
    assert(r.vector == direction);

    std::cout << "Passed!" << std::endl;
}

void test_point_on_ray(void)
{
    std::cout << "Testing point on ray" << std::endl;

    ray::Ray r(tuple::make_point(2, 3, 4), tuple::make_vector(1, 0, 0));

    assert(r.pose(0) == tuple::make_point(2, 3, 4));
    assert(r.pose(1) == tuple::make_point(3, 3, 4));
    assert(r.pose(-1) == tuple::make_point(1, 3, 4));
    assert(r.pose(2.5) == tuple::make_point(4.5, 3, 4));

    std::cout << "Passed!" << std::endl;
}

void test_sphere_ray_intersection(void)
{
    std::cout << "Testing ray intersection with a sphere" << std::endl;

    ray::Ray r1(tuple::make_point(0, 0, -5), tuple::make_vector(0, 0, 1));

    shape::Sphere s;

    std::vector<double> xs1 = intersect(s, r1);

    assert(xs1.size() == 2);
    assert(xs1[0] = 4.0);
    assert(xs1[1] = 6.0);

    ray::Ray r2(tuple::make_point(0, 1, -5), tuple::make_vector(0, 0, 1));

    std::vector<double> xs2 = intersect(s, r2);

    assert(xs2.size() == 2);
    assert(xs2[0] = 5.0);
    assert(xs2[1] = 5.0);

    ray::Ray r3(tuple::make_point(0, 2, -5), tuple::make_vector(0, 0, 1));

    std::vector<double> xs3 = intersect(s, r3);

    std::cout << xs3.size() << std::endl;

    assert(xs3.size() == 0);

    std::cout << "Passed!" << std::endl;
}
