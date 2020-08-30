#include <cassert>
#include <iostream>

#include "ppm.hpp"
#include "colour.hpp"
#include "test_canvas.hpp"

void test_canvas(void)
{
    test_canvas_creation();
    test_ppm();
}

void test_canvas_creation(void)
{
    std::cout << "Testing canvas creation" << std::endl;

    ppm::PortablePixMap c({0, 0}, 10, 20);

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
    ppm::PortablePixMap c({0, 0}, 10, 2, col);

    std::vector<ppm::PortablePixMap> v;
    v.push_back(c);
    touch_ppm(v, "ray.ppm");

    std::cout << "Passed!" << std::endl;
}
