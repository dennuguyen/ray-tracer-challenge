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

private:
    std::vector<shape::Shape> obj;
    std::vector<shades::PointLight> light;
};
} // namespace scene
#endif // WORLD_HPP_