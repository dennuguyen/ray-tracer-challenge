#ifndef PPM_HPP_
#define PPM_HPP_

#include <string>
#include <ctime>
#include <vector>

#include "alphabet.hpp"
#include "colour.hpp"
#include "utils.hpp"

namespace ppm {
class PortablePixMap {
   public:
    PortablePixMap(uint width_, uint height_);
    PortablePixMap(uint width_, uint height_, colour::Colour fill_);
    PortablePixMap(std::pair<uint, uint> origin_, uint width_, uint height_);
    PortablePixMap(std::pair<uint, uint> origin_, uint width_, uint height_, colour::Colour fill_);
    ~PortablePixMap();

    /* Getters */
    const uint get_x0();
    const uint get_y0();
    const uint get_width();
    const uint get_height();
    const std::vector<colour::Colour>& get_data();
    const std::time_t get_time();

    /* Write */
    void write_pixel(uint x, uint y, colour::Colour rgb);

    /* Draw */
    void draw_line(std::pair<uint, uint> pt1, std::pair<uint, uint> pt2, colour::Colour rgb);
    void draw_box(std::pair<uint, uint> pt, uint len1, uint len2, colour::Colour rgb);
    void draw_quadrilateral(std::pair<uint, uint> pt1, std::pair<uint, uint> pt2, std::pair<uint, uint> pt3, std::pair<uint, uint> pt4, colour::Colour rgb);
    void draw_letter(std::pair<uint, uint> pt, alphabet::Letter letter, uint size, colour::Colour rgb);

    /* Operators */
    inline colour::Colour& operator()(int x, int y) { return data[x + y * width]; };

   private:
    std::time_t mtime;
    std::pair<uint, uint> origin;
    const uint width;
    const uint height;
    std::vector<colour::Colour> data;
};

void touch_ppm(std::vector<PortablePixMap>& layers, const std::string file_name);
}  // namespace ppm

#endif  // PPM_HPP_
