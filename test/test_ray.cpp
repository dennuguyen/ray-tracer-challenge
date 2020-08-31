#include <iostream>
#include <cassert>

#include "intersection.hpp"
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

    std::vector<intersection::Intersection> xs1 = intersection::intersect(s, r1);

    assert(xs1.size() == 2);
    assert(xs1[0].t = 4.0);
    assert(xs1[1].t = 6.0);

    ray::Ray r2(tuple::make_point(0, 1, -5), tuple::make_vector(0, 0, 1));

    std::vector<intersection::Intersection> xs2 = intersection::intersect(s, r2);

    assert(xs2.size() == 2);
    assert(xs2[0].t = 5.0);
    assert(xs2[1].t = 5.0);

    ray::Ray r3(tuple::make_point(0, 2, -5), tuple::make_vector(0, 0, 1));

    std::vector<intersection::Intersection> xs3 = intersection::intersect(s, r3);

    assert(xs3.size() == 0);

    ray::Ray r4(tuple::make_point(0, 0, 0), tuple::make_vector(0, 0, 1));

    std::vector<intersection::Intersection> xs4 = intersection::intersect(s, r4);

    assert(xs4.size() == 2);
    assert(xs4[0].t = -1.0);
    assert(xs4[1].t = 1.0);

    ray::Ray r5(tuple::make_point(0, 0, 5), tuple::make_vector(0, 0, 1));

    std::vector<intersection::Intersection> xs5 = intersection::intersect(s, r5);

    assert(xs5.size() == 2);
    assert(xs5[0].t = -6.0);
    assert(xs5[1].t = -4.0);

    std::cout << "Passed!" << std::endl;
}
