#include <cassert>
#include <iostream>

#include "colour.hpp"
#include "tuple.hpp"
#include "test.hpp"
#include "utils.hpp"

namespace test_colour
{
void test_colour(void)
{
    test_colour_rgb();
    test_colour_add();
    test_colour_minus();
    test_colour_scalar_multiply();
    test_colour_multiply();
}

void test_colour_rgb(void)
{
    std::cout << "Testing colour tuple" << std::endl;

    colour::Colour col(-0.5, 0.4, 1.7);

    assert(col.r == -0.5);
    assert(col.g == 0.4);
    assert(col.b == 1.7);

    std::cout << "Passed!" << std::endl;
}

void test_colour_add(void)
{
    std::cout << "Testing addition of colours" << std::endl;

    colour::Colour c1(0.9, 0.6, 0.75);
    colour::Colour c2(0.7, 0.1, 0.25);
    colour::Colour c3 = colour::add(c1, c2);

    assert(c3.r == 1.6);
    assert(c3.g == 0.7);
    assert(c3.b == 1.0);

    std::cout << "Passed!" << std::endl;
}

void test_colour_minus(void)
{
    std::cout << "Testing subtraction of colours" << std::endl;

    colour::Colour c1(0.9, 0.6, 0.75);
    colour::Colour c2(0.7, 0.1, 0.25);
    colour::Colour c3 = colour::minus(c1, c2);

    assert(d_cmp(c3.r, 0.2, colour::EPSILON));
    assert(d_cmp(c3.g, 0.5, colour::EPSILON));
    assert(d_cmp(c3.b, 0.5, colour::EPSILON));

    std::cout << "Passed!" << std::endl;
}

void test_colour_scalar_multiply(void)
{
    std::cout << "Testing scalar multiplication of colour" << std::endl;

    colour::Colour c1(0.2, 0.3, 0.4);
    colour::Colour c2 = colour::scalar_multiply(c1, 2);

    assert(d_cmp(c2.r, 0.4, colour::EPSILON));
    assert(d_cmp(c2.g, 0.6, colour::EPSILON));
    assert(d_cmp(c2.b, 0.8, colour::EPSILON));

    std::cout << "Passed!" << std::endl;
}

void test_colour_multiply(void)
{
    std::cout << "Testing multiplication of colours" << std::endl;

    colour::Colour c1(1, 0.2, 0.4);
    colour::Colour c2(0.9, 1, 0.1);
    colour::Colour c3 = colour::colour_multiply(c1, c2);

    assert(d_cmp(c3.r, 0.9, colour::EPSILON));
    assert(d_cmp(c3.g, 0.2, colour::EPSILON));
    assert(d_cmp(c3.b, 0.04, colour::EPSILON));

    std::cout << "Passed!" << std::endl;
}
} // namespace test_colour
