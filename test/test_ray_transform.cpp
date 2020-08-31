#include <iostream>
#include <cassert>
#include <cmath>

#include "intersection.hpp"
#include "matrix.hpp"
#include "ray.hpp"
#include "shape.hpp"
#include "sphere.hpp"

#include "test_ray_transform.hpp"

void test_ray_transform(void)
{
    test_ray_translation();
    test_ray_scaling();
    test_sphere_transform();
    test_scaled_sphere_intersection();
}

void test_ray_translation(void)
{
    std::cout << "Testing ray translation" << std::endl;

    ray::Ray r1(tuple::make_point(1, 2, 3), tuple::make_vector(0, 1, 0));

    matrix::Matrix m = matrix::translate(3, 4, 5);

    ray::Ray r2 = ray::transform(r1, m);

    assert(r2.origin == tuple::make_point(4, 6, 8));
    assert(r2.vector == tuple::make_vector(0, 1, 0));

    std::cout << "Passed!" << std::endl;
}

void test_ray_scaling(void)
{
    std::cout << "Testing ray scaling" << std::endl;

    ray::Ray r1(tuple::make_point(1, 2, 3), tuple::make_vector(0, 1, 0));

    matrix::Matrix m = matrix::scale(2, 3, 4);

    ray::Ray r2 = ray::transform(r1, m);

    assert(r2.origin == tuple::make_point(2, 6, 12));
    assert(r2.vector == tuple::make_vector(0, 3, 0));

    std::cout << "Passed!" << std::endl;
}

void test_sphere_transform(void)
{
    std::cout << "Testing sphere transformation matrix" << std::endl;

    shape::Sphere s;

    assert(s.get_transform() == matrix::Matrix());

    matrix::Matrix t = matrix::translate(2, 3, 4);
    s.set_transform(t);

    assert(s.get_transform() == t);

    std::cout << "Passed!" << std::endl;
}

void test_scaled_sphere_intersection(void)
{
    std::cout << "Testing scaled sphere intersections" << std::endl;

    ray::Ray r(tuple::make_point(0, 0, -5), tuple::make_vector(0, 0, 1));
    shape::Sphere s;

    s.set_transform(matrix::scale(2, 2, 2));
    std::vector<intersection::Intersection> xs1 = intersection::intersect(s, r);

    assert(xs1.size() == 2);
    assert(xs1[0].t == 3);
    assert(xs1[1].t == 7);

    s.set_transform(matrix::translate(5, 0, 0));
    std::vector<intersection::Intersection> xs2 = intersection::intersect(s, r);

    assert(xs2.size() == 0);

    std::cout << "Passed!" << std::endl;
}