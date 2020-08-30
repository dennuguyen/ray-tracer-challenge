#include <iostream>
#include <string>

#include "ppm.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Incorrect number of arguments " << argc << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string file_name = argv[1];
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
    ppm::PortablePixMap map({0, 0}, 720, 720);
    ppm::PortablePixMap mm({0, 0}, 300, 300, colour::NONE);

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
