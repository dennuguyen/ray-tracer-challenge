#ifndef WORLD_HPP_
#define WORLD_HPP_

#include "shades.hpp"
#include "shape.hpp"

namespace scene
{
class World
{
public:
    World(void);
    World(std::vector<shape::Shape> obj_, std::vector<shades::PointLight> light_);

    const std::vector<shape::Shape> get_objects(void);
    const std::vector<shades::PointLight> get_lights(void);

private:
    std::vector<shape::Shape> obj;
    std::vector<shades::PointLight> light;
};
} // namespace scene
#endif // WORLD_HPP_