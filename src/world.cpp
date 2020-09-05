#include "world.hpp"

namespace scene
{
World::World(void) : obj({}), light({}) {}

World::World(std::vector<shape::Shape> obj_, std::vector<shades::PointLight> light_)
    : obj(obj_)
    , light(light_)
{}

const std::vector<shape::Shape> World::get_objects(void) { return obj; }
const std::vector<shades::PointLight> World::get_lights(void) { return light; }

} // namespace scene