#include <iostream>
#include <string>

#include "ppm.hpp"

#include "test_canvas.hpp"
#include "test_colour.hpp"
#include "test_intersection.hpp"
#include "test_matrix.hpp"
#include "test_projectile.hpp"
#include "test_ray.hpp"
#include "test_ray_transform.hpp"
#include "test_matrix_transform.hpp"
#include "test_tuple.hpp"

int main(int argv, char *argc[])
{
    if (argv < 2)
    {
        std::cerr << "Incorrect number of arguments " << argv << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < argv; i++)
    {
        std::string arg = argc[i];
        if (arg == "test_canvas") { test_canvas(); }
        if (arg == "test_colour") { test_colour(); }
        if (arg == "test_intersection") { test_intersection(); }
        if (arg == "test_matrix") { test_matrix(); }
        if (arg == "test_matrix_transform") { test_matrix_transform(); }
        if (arg == "test_projectile") { test_projectile(); }
        if (arg == "test_ray") { test_ray(); }
        if (arg == "test_ray_transform") { test_ray_transform(); }
        if (arg == "test_tuple") { test_tuple(); }
    }

    std::string file_name = "hello.ppm";
    long unsigned int file_type = file_name.find_last_of(".");
    if (file_type == std::string::npos)
    {
        std::cerr << file_name << " has no extension" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (file_name.substr(file_type) != ".ppm")
    {
        std::cerr << "Incorrect file type " << file_name.substr(file_type) << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<ppm::PortablePixMap> canvas;
    ppm::PortablePixMap map(720, 720);
    ppm::PortablePixMap mm(300, 300, colour::NONE);

    // map.draw_line({100, 100}, {10, 20}, colour::BLUE, 100);
    // map.draw_box({100, 100}, 100, 200, colour::BLUE);
    mm.draw_letter({50, 100}, alphabet::THREE, 7, colour::RED);
    map.draw_letter({50, 100}, alphabet::FOUR, 7, colour::BLUE);
    map.draw_letter({100, 100}, alphabet::FIVE, 7, colour::BLUE);
    map.draw_letter({150, 100}, alphabet::SIX, 7, colour::BLUE);
    map.draw_letter({200, 100}, alphabet::NINE, 7, colour::BLUE);
    map.draw_letter({250, 100}, alphabet::ZERO, 7, colour::BLUE);

    canvas.push_back(map);
    canvas.push_back(mm);
    ppm::touch_ppm(canvas, file_name);
    return EXIT_SUCCESS;
}
