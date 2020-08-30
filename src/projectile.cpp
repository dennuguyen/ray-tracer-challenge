#include "projectile.hpp"

namespace shapes
{
Projectile::Projectile(void)
    : pose(tuple::make_point(0, 1, 0))
    , head(tuple::make_vector(1, 1, 0))
{
}

tuple::Tuple Projectile::get_pose(void)
{
    return pose;
}

tuple::Tuple Projectile::get_head(void)
{
    return head;
}

void Projectile::set_pose(tuple::Tuple new_pose)
{
    pose = new_pose;
}

void Projectile::set_head(tuple::Tuple new_head)
{
    head = new_head;
}
} // namespace shapes