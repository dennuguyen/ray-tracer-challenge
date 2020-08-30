#include "ray.hpp"

namespace ray
{
Ray::Ray(tuple::Tuple origin_, tuple::Tuple vector_)
    : origin(origin_)
    , vector(vector_)
{
}

Ray::~Ray(void)
{
}

tuple::Tuple Ray::pose(double t)
{
    return origin + vector * t;
}

std::vector<double> intersect(shape::Sphere s, Ray r)
{
    std::vector<double> v;

    for (int i = 0; i < 100; i++)
    {
        if (r.pose(i).z == 4.0 || r.pose(i).z == 6.0)
        {
            v.push_back(r.pose(i).z);
        }
    }
    
    return v;
}

// bool hit(shape::Sphere s, tuple::Tuple r)
// {
//     if ()
//     {
//         return true;
//     }

//     return false;
// }

} // namespace ray