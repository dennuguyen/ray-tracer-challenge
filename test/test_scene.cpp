#include <cassert>
#include <iostream>

#include "colour.hpp"
#include "shades.hpp"
#include "shape.hpp"
#include "sphere.hpp"
#include "world.hpp"
#include "test.hpp"

namespace test_scene
{
void test_scene(void)
{
    test_empty_world();
    test_default_world();
    test_world_ray_intersection();
}

void test_empty_world(void)
{
    std::cout << "Testing empty world initialisation" << std::endl;

    scene::World w;

    assert(w.get_objects().size() == 0);
    assert(w.get_lights().size() == 0);

    std::cout << "Passed!" << std::endl;
}

void test_default_world(void)
{
    std::cout << "Testing default world initialisation" << std::endl;

    std::vector<shape::Shape> objects = {
        shape::Sphere(
            matrix::scale(0.5, 0.5, 0.5),
            shades::Material(colour::Colour(0.8, 1.0, 0.6), 0, 0.7, 0.2, 0))
    };
    std::vector<shades::PointLight> lights = {
        shades::PointLight(tuple::make_point(-10, 10, -10), colour::WHITE) };

    scene::World w(objects, lights);

    assert(w.get_objects().size() == 1);
    assert(w.get_lights().size() == 1);
    assert(w.get_objects()[0] == objects[0]);
    assert(w.get_lights()[0] == lights[0]);

    std::cout << "Passed!" << std::endl;
}

void test_world_ray_intersection(void)
{
    std::cout << "Testing world ray intersections" << std::endl;

    std::vector<shape::Shape> objects = {
        shape::Sphere(
            matrix::scale(0.5, 0.5, 0.5),
            shades::Material(colour::Colour(0.8, 1.0, 0.6), 0, 0.7, 0.2, 0))
    };
    std::vector<shades::PointLight> lights = {
        shades::PointLight(tuple::make_point(-10, 10, -10), colour::WHITE) };

    scene::World w(objects, lights);

    assert(w.get_objects().size() == 1);
    assert(w.get_lights().size() == 1);
    assert(w.get_objects()[0] == objects[0]);
    assert(w.get_lights()[0] == lights[0]);

    std::cout << "Passed!" << std::endl;
}

} // namespace test_scene
