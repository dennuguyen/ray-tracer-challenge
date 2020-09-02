#include <cassert>
#include <cmath>
#include <iostream>

#include "light.hpp"
#include "shades.hpp"
#include "shape.hpp"
#include "sphere.hpp"

#include "test_shades.hpp"
#include "utils.hpp"

void test_shades(void)
{
    test_sphere_normal();
    test_transformed_sphere_normal();
    test_reflect();
    test_point_light();
    test_material();
    test_lighting();
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

    tuple::Tuple r1 = shades::reflect(v1, n1);

    assert(r1 == tuple::make_vector(1, 1, 0));

    tuple::Tuple v2 = tuple::make_vector(0, -1, 0);
    tuple::Tuple n2 = tuple::make_vector(sqrt(2) / 2, sqrt(2) / 2, 0);

    tuple::Tuple r2 = shades::reflect(v2, n2);

    assert(r2 == tuple::make_vector(1, 0, 0));

    std::cout << "Passed!" << std::endl;
}

void test_point_light(void)
{
    std::cout << "Testing point light" << std::endl;

    shades::PointLight p(tuple::Tuple(0, 0, 0, 0), colour::Colour(1, 1, 1));
    
    assert(p.get_position() == tuple::Tuple(0, 0, 0, 0));
    assert(p.get_intensity() == colour::Colour(1, 1, 1));

    std::cout << "Passed!" << std::endl;
}

void test_material(void)
{
    std::cout << "Testing material" << std::endl;

    shades::Material m1;

    assert(m1.colour == colour::WHITE);
    assert(d_cmp(m1.ambient, 0.1, tuple::EPSILON));
    assert(d_cmp(m1.diffuse, 0.9, tuple::EPSILON));
    assert(d_cmp(m1.specular, 0.9, tuple::EPSILON));
    assert(d_cmp(m1.shiny, 200.0, tuple::EPSILON));

    shape::Sphere s;
    shades::Material m2;
    m2.ambient = 1;
    s.set_material(m2);

    assert(s.get_material() == m2);

    std::cout << "Passed!" << std::endl;
}

void test_lighting(void)
{
    std::cout << "Testing lighting" << std::endl;

    shades::Material m;
    tuple::Tuple pos = tuple::make_point(0, 0, 0);

    tuple::Tuple e1 = tuple::make_vector(0, 0, -1);
    tuple::Tuple n1 = tuple::make_vector(0, 0, -1);
    shades::PointLight l1(tuple::make_point(0, 0, -10), colour::WHITE);

    colour::Colour c1 = shades::lighting(m, l1, pos, e1, n1);

    assert(c1 == colour::Colour(1.9, 1.9, 1.9));

    tuple::Tuple e2 = tuple::make_vector(0, sqrt(2) / 2, -sqrt(2) / 2);
    tuple::Tuple n2 = tuple::make_vector(0, 0, -1);
    shades::PointLight l2(tuple::make_point(0, 0, -10), colour::WHITE);

    colour::Colour c2 = shades::lighting(m, l2, pos, e2, n2);

    assert(c2 == colour::Colour(1.0, 1.0, 1.0));

    tuple::Tuple e3 = tuple::make_vector(0, 0, -1);
    tuple::Tuple n3 = tuple::make_vector(0, 0, -1);

    shades::PointLight l3(tuple::make_point(0, 10, -10), colour::WHITE);

    colour::Colour c3 = shades::lighting(m, l3, pos, e3, n3);

    assert(c3 == colour::Colour(0.7364, 0.7364, 0.7364));

    tuple::Tuple e4 = tuple::make_vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
    tuple::Tuple n4 = tuple::make_vector(0, 0, -1);

    shades::PointLight l4(tuple::make_point(0, 10, -10), colour::WHITE);

    colour::Colour c4 = shades::lighting(m, l4, pos, e4, n4);

    assert(c4 == colour::Colour(1.6364, 1.6364, 1.6364));

    tuple::Tuple e5 = tuple::make_vector(0, 0, -1);
    tuple::Tuple n5 = tuple::make_vector(0, 0, -1);

    shades::PointLight l5(tuple::make_point(0, 0, 10), colour::WHITE);

    colour::Colour c5 = shades::lighting(m, l5, pos, e5, n5);

    assert(c5 == colour::Colour(0.1, 0.1, 0.1));

    std::cout << "Passed!" << std::endl;
}