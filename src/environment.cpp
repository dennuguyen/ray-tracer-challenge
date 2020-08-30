#include "environment.hpp"

namespace shapes
{
Environment::Environment(void)
    : gravity(tuple::make_vector(0, -0.1, 0))
    , wind(tuple::make_vector(-0.01, 0, 0))
{
}

tuple::Tuple Environment::get_gravity(void)
{
    return gravity;
}
tuple::Tuple Environment::get_wind(void)
{
    return wind;
}
} // namespace shapes