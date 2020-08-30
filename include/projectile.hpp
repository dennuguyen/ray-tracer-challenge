#ifndef PROJECTILE_HPP_
#define PROJECTILE_HPP_

#include "environment.hpp"
#include "tuple.hpp"

namespace shapes
{
class Projectile
{
public:
    Projectile(void);

    tuple::Tuple get_pose(void);
    tuple::Tuple get_head(void);

    void set_pose(tuple::Tuple new_pose);
    void set_head(tuple::Tuple new_head);

private:
    tuple::Tuple pose;
    tuple::Tuple head;
};
} // namespace shapes
#endif // PROJECTILE_HPP_