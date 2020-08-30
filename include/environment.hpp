#ifndef ENVIRONMENT_HPP_
#define ENVIRONMENT_HPP_

#include "tuple.hpp"

namespace shapes
{
class Environment
{
public:
    Environment(void);

    tuple::Tuple get_gravity(void);
    tuple::Tuple get_wind(void);

private:
    tuple::Tuple gravity;
    tuple::Tuple wind;
};
} // namespace shapes
#endif // ENVIRONMENT_HPP_