#include <cassert>
#include <iostream>

#include "intersection.hpp"
#include "ray.hpp"
#include "shape.hpp"
#include "test_intersection.hpp"

void test_intersection(void)
{
    test_intersection_creation();
    test_intersection_list();
    test_intersection_object();
    test_positive_hits();
    test_both_hits();
    test_negative_hits();
    test_hits();
}

void test_intersection_creation(void)
{
    std::cout << "Testing intersection creation" << std::endl;

    shape::Sphere s;
    intersection::Intersection i(s, 3.5);

    assert(i.obj == s);
    assert(i.t == 3.5);

    std::cout << "Passed!" << std::endl;
}

void test_intersection_list(void)
{
    std::cout << "Testing intersection list" << std::endl;

    shape::Sphere s;
    intersection::Intersection i1(s, 1);
    intersection::Intersection i2(s, 2);

    std::vector<intersection::Intersection> xs = {i1, i2};

    assert(xs.size() == 2);
    assert(xs[0].t == 1);
    assert(xs[1].t == 2);

    std::cout << "Passed!" << std::endl;
}

void test_intersection_object(void)
{
    std::cout << "Testing intersection of objects" << std::endl;

    ray::Ray r(tuple::make_point(0, 0, -5), tuple::make_vector(0, 0, 1));
    shape::Sphere s;
    std::vector<intersection::Intersection> xs = intersection::intersect(s, r);

    assert(xs.size() == 2);
    assert(xs[0].obj == s);
    assert(xs[1].obj == s);

    std::cout << "Passed!" << std::endl;
}

void test_positive_hits(void)
{
    std::cout << "Testing positive hits" << std::endl;

    shape::Sphere s;
    intersection::Intersection i1(s, 1);
    intersection::Intersection i2(s, 2);
    std::vector<intersection::Intersection> xs = {i1, i2};

    intersection::Intersection i = intersection::hit(xs);

    assert(i == i1);

    std::cout << "Passed!" << std::endl;
}

void test_both_hits(void)
{
    std::cout << "Testing positive and negative hits" << std::endl;

    shape::Sphere s;
    intersection::Intersection i1(s, -1);
    intersection::Intersection i2(s, 1);
    std::vector<intersection::Intersection> xs = {i1, i2};

    intersection::Intersection i = intersection::hit(xs);

    assert(i == i2);

    std::cout << "Passed!" << std::endl;
}

void test_negative_hits(void)
{
    std::cout << "Testing negative hits" << std::endl;

    shape::Sphere s;
    intersection::Intersection i1(s, -2);
    intersection::Intersection i2(s, -1);
    std::vector<intersection::Intersection> xs = {i1, i2};

    intersection::Intersection i = intersection::hit(xs);

    // assert(i.t == NULL);

    std::cout << "Passed!" << std::endl;
}

void test_hits(void)
{
    std::cout << "Testing random hits" << std::endl;

    shape::Sphere s;
    intersection::Intersection i1(s, 5);
    intersection::Intersection i2(s, 7);
    intersection::Intersection i3(s, -3);
    intersection::Intersection i4(s, 2);
    std::vector<intersection::Intersection> xs = {i1, i2, i3, i4};

    intersection::Intersection i = intersection::hit(xs);

    assert(i == i4);

    std::cout << "Passed!" << std::endl;
}
