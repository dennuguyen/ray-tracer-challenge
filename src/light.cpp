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

} // namespace shades