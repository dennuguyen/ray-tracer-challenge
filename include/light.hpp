#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "colour.hpp"
#include "tuple.hpp"

namespace shades
{
class PointLight
{
    public:
    PointLight(tuple::Tuple position_, colour::Colour intensity_);
    ~PointLight(void);

    const tuple::Tuple get_position(void);
    const colour::Colour get_intensity(void);

    private:
    tuple::Tuple position;
    colour::Colour intensity;
};

bool is_same_light(PointLight a, PointLight b);
inline bool operator==(PointLight a, PointLight b) { return is_same_light(a, b); };

} // namespace shades

#endif // LIGHT_HPP_
