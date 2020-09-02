#ifndef SHADES_HPP_
#define SHADES_HPP_

#include "colour.hpp"
#include "light.hpp"
#include "tuple.hpp"

namespace shades
{
struct Material
{
    Material(void);
    Material(colour::Colour colour_, float ambient_, float diffuse_, float specular_, float shiny_);
    ~Material(void);

    colour::Colour colour;
    float ambient;
    float diffuse;
    float specular;
    float shiny;
};

tuple::Tuple reflect(tuple::Tuple v, tuple::Tuple n);

colour::Colour lighting(Material material,
                        PointLight light,
                        tuple::Tuple position,
                        tuple::Tuple eyev,
                        tuple::Tuple normalv);

bool is_same_material(Material a, Material b);

inline bool operator==(Material a, Material b) { return is_same_material(a, b); };

} // namespace shades

#endif // SHADES_HPP_