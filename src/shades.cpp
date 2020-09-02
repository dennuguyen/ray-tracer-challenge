#include "shades.hpp"
#include "utils.hpp"

namespace shades
{
Material::Material(void)
    : colour(colour::WHITE)
    , ambient(0.1)
    , diffuse(0.9)
    , specular(0.9)
    , shiny(200.0)
{}

Material::Material(colour::Colour colour_, float ambient_, float diffuse_, float specular_, float shiny_)
    : colour(colour_)
    , ambient(ambient_)
    , diffuse(diffuse_)
    , specular(specular_)
    , shiny(shiny_)
{}

Material::~Material(void) {}

tuple::Tuple reflect(tuple::Tuple v, tuple::Tuple n)
{
    return v - n * 2 * dot(v, n);
}

colour::Colour lighting(Material material,
                        PointLight light,
                        tuple::Tuple position,
                        tuple::Tuple eyev,
                        tuple::Tuple normalv)
{
    colour::Colour effective_colour = material.colour * light.get_intensity();
    tuple::Tuple lightv = tuple::normalise(light.get_position() - position);
    double light_dot_normal = tuple::dot(lightv, normalv);

    colour::Colour ambient(effective_colour *= material.ambient);
    colour::Colour diffuse(colour::BLACK);
    colour::Colour specular(colour::BLACK);

    if (light_dot_normal >= 0)
    {
        diffuse = effective_colour *= material.diffuse * light_dot_normal;
        
        tuple::Tuple reflectv = reflect(-lightv, normalv);
        double reflect_dot_eye = tuple::dot(reflectv, eyev);
        
        if (reflect_dot_eye > 0)
        {
            double factor = pow(reflect_dot_eye, material.shiny);
            specular = light.get_intensity() *= material.specular * factor;
        }
    }

    return ambient + diffuse + specular;
}

bool is_same_material(Material a, Material b)
{
    return a.colour == b.colour
        && d_cmp(a.ambient, b.ambient, tuple::EPSILON)
        && d_cmp(a.diffuse, b.diffuse, tuple::EPSILON)
        && d_cmp(a.specular, b.specular, tuple::EPSILON)
        && d_cmp(a.shiny, b.shiny, tuple::EPSILON);
}

} // namespace shades