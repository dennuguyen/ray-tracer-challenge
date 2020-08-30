#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

#include "colour.hpp"
#include "ppm.hpp"

static uint scale_rgb(double input)
{
    if (input == NOFILL)
        return input;

    if (input < 0.0)
        input = 0.0;
    else if (input > 1.0)
        input = 1.0;

    return std::round(input * 255);
}

namespace ppm
{
    PortablePixMap::PortablePixMap(std::pair<uint, uint> origin_, uint width_, uint height_)
        : origin(origin_), width(width_), height(height_)
    {
        data.resize(width * height, colour::BLACK);
    }

    PortablePixMap::PortablePixMap(std::pair<uint, uint> origin_, uint width_, uint height_, colour::Colour fill_)
        : origin(origin_), width(width_), height(height_)
    {
        data.resize(width * height, fill_);
    }

    PortablePixMap::~PortablePixMap() {}

    const uint PortablePixMap::get_x0()
    {
        return origin.first;
    }

    const uint PortablePixMap::get_y0()
    {
        return origin.second;
    }

    const uint PortablePixMap::get_width()
    {
        return width;
    }

    const uint PortablePixMap::get_height()
    {
        return height;
    }

    const std::vector<colour::Colour> &PortablePixMap::get_data()
    {
        return data;
    }

    const std::time_t PortablePixMap::get_time()
    {
        return mtime;
    }


    void PortablePixMap::write_pixel(uint x, uint y, colour::Colour rgb)
    {
        if (rgb == colour::NONE)
            return;

        mtime = std::time(nullptr);
        data[x + y * width] = rgb;
    }

    void PortablePixMap::draw_line(std::pair<uint, uint> pt1, std::pair<uint, uint> pt2, colour::Colour rgb)
    {
        std::pair<uint, uint> x_bound = pt1.first < pt2.first ? std::pair<uint, uint>{pt1.first, pt2.first} : std::pair<uint, uint>{pt2.first, pt1.first};
        std::pair<uint, uint> y_bound = pt1.second < pt2.second ? std::pair<uint, uint>{pt1.second, pt2.second} : std::pair<uint, uint>{pt2.second, pt1.second};

        uint dx = x_bound.second - x_bound.first;
        uint dy = y_bound.second - y_bound.first;

        if (dx == 0)
            for (uint y = y_bound.first; y < y_bound.second && y < get_height(); y++)
                write_pixel(x_bound.first, y, rgb);

        for (uint x = x_bound.first; x < x_bound.second && x < get_width(); x++)
        {
            uint y = ((x - x_bound.first) * dy / dx) + y_bound.first;
            write_pixel(x, y, rgb);
        }
    }

    void PortablePixMap::draw_box(std::pair<uint, uint> pt, uint len1, uint len2, colour::Colour rgb)
    {
        for (uint x = pt.first; x < len1 + pt.first && x < get_width(); x++)
            for (uint y = pt.second; y < len2 + pt.second && y < get_height(); y++)
                write_pixel(x, y, rgb);
    }

    void PortablePixMap::draw_quadrilateral(std::pair<uint, uint> pt1, std::pair<uint, uint> pt2, std::pair<uint, uint> pt3, std::pair<uint, uint> pt4, colour::Colour rgb)
    {
    }

    void PortablePixMap::draw_letter(std::pair<uint, uint> pt, alphabet::Letter letter, uint size, colour::Colour rgb)
    {
        for (auto &v : letter.data)
            draw_box({pt.first + v.first * size, pt.second - v.second * size}, size, size, rgb);
    }

    void touch_ppm(std::vector<PortablePixMap>& layers, const std::string file_name)
    {
        // std::sort(layers.begin(), layers.end(), [](const PortablePixMap& a, const PortablePixMap& b) { return a.get_time() < b.get_time(); });

        std::stringstream buffer;
        PortablePixMap canvas({0, 0}, layers.front().get_width(), layers.front().get_height());

        buffer << "P3" << std::endl;
        buffer << canvas.get_width() << " " << canvas.get_height() << std::endl;
        buffer << "255" << std::endl;

        for(auto &layer : layers)
            for (uint j = 0; j < canvas.get_height() && j < layer.get_height() + layer.get_y0(); j++)
                for (uint i = 0; i < canvas.get_width() && i < layer.get_width() + layer.get_x0(); i++)
                    canvas.write_pixel(i + layer.get_x0(), j + layer.get_y0(), layer(i, j));

        for (uint j = 0, k = 1; j < canvas.get_height(); j++)
        {
            for (uint i = 0; i < canvas.get_width(); i++, k++)
            {
                buffer << scale_rgb(canvas(i, j).r) << " ";
                buffer << scale_rgb(canvas(i, j).g) << " ";
                buffer << scale_rgb(canvas(i, j).b) << ((k % 4 == 0) ? "\n" : " ");
            }

            buffer << std::endl;
        }

        std::ofstream ppm_file(file_name);
        ppm_file << buffer.rdbuf();
        ppm_file.close();
    }
} // namespace ppm
