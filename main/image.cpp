#include <iostream>
#include <string>

#include "ppm.hpp"
#include "ray.hpp"
#include "shape.hpp"
#include "sphere.hpp"
#include "intersection.hpp"
#include "tuple.hpp"

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
        if (arg == "test_all")
        {
            test_canvas();
            test_colour();
            test_intersection();
            test_matrix();
            test_matrix_transform();
            test_projectile();
            test_ray();
            test_ray_transform();
            test_tuple();
            break;
        }
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

    std::string file_name = argc[1];
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

    //////////////////////////////////////////////////////////////////////////
    std::vector<ppm::PortablePixMap> canvas;
    ppm::PortablePixMap map(100, 100);

    double wall_z = 10.0;
    double wall_size = 7.0;
    double pixel_size = wall_size / 100;
    tuple::Tuple ray_origin = tuple::make_point(0, 0, -5);
    shape::Sphere s;

    for (int y = 0; y < 100; y++)
    {
        double world_y = (wall_size / 2) - (pixel_size * y);
        for (int x = 0; x < 100; x++)
        {
            double world_x = -(wall_size / 2) + (pixel_size * x);
            tuple::Tuple position = tuple::make_point(world_x, world_y, wall_z);
            ray::Ray r(ray_origin, tuple::normalise(position - ray_origin));
            std::vector<intersection::Intersection> xs = intersection::intersect(s, r);

            if (intersection::hit(xs).empty == false)
            {
                map.write_pixel(x, y, colour::RED);
            }
        }
    }

    canvas.push_back(map);
    ppm::touch_ppm(canvas, file_name);
    //////////////////////////////////////////////////////////////////////////

    return EXIT_SUCCESS;
}
