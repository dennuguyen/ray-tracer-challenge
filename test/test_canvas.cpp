#include <cassert>
#include <iostream>

#include "canvas.hpp"
#include "colour.hpp"
#include "main.hpp"
#include "test_canvas.hpp"

void test_canvas(void)
{
    test_canvas_creation();
    test_ppm();
}

void test_canvas_creation(void)
{
    std::cout << "Testing canvas creation" << std::endl;

    canvas::Canvas c(10, 20);

    assert(c.get_width() == 10);
    assert(c.get_height() == 20);

    for (auto const & pixel : c.get_data())
    {
        assert(pixel.r == 0);
        assert(pixel.g == 0);
        assert(pixel.b == 0);
    }

    std::cout << "Passed!" << std::endl;
}

void test_ppm(void)
{
    std::cout << "Testing ppm creation" << std::endl;

    colour::Colour col(1.0, 0.8, 0.6);    
    canvas::Canvas c(10, 2, col);

    touch_ppm(c);

    std::cout << "Passed!" << std::endl;
}
