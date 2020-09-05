#include "light.hpp"

namespace shades
{
PointLight::PointLight(tuple::Tuple position_, colour::Colour intensity_)
    : position(position_)
    , intensity(intensity_)
{}

PointLight::~PointLight(void) {}

const tuple::Tuple PointLight::get_position(void)
{
    return position;
}

const colour::Colour PointLight::get_intensity(void)
{
    return intensity;
}

bool is_same_light(PointLight a, PointLight b)
{
    return a.get_position() == b.get_position()
        && a.get_intensity() == b.get_intensity();
}

} // namespace shades