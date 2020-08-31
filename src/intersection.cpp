#include "intersection.hpp"

#include <algorithm>
#include <cmath>
#include <numeric>

namespace intersection
{
    Intersection::Intersection() : empty(true) {}

    Intersection::Intersection(shape::Shape obj_, double t_)
        : empty(false)
        , obj(obj_)
        , t(t_)
    {}

    Intersection::~Intersection() {}

    bool is_same_intersection(Intersection a, Intersection b)
    {
        return (a.obj == b.obj && a.t == b.t);
    }

    bool is_hit(Intersection a, Intersection b)
    {
        return (a.t >= 0 && a.t < b.t);
    }

    Intersection hit(std::vector<Intersection> v)
    {
        Intersection min;
        for (auto & i : v)
            if (i.t >= 0)
            {
                min = i;
                break;
            }
        
        if (min.empty == true)
            return min;

        for (auto & i : v)
            if (is_hit(i, min) == true)
                min = i;

        return min;
    }

    std::vector<Intersection> intersect(shape::Sphere s, ray::Ray r)
    {
        tuple::Tuple sphere_to_ray = r.origin - s.get_origin();
        double a = tuple::dot(r.vector, r.vector);
        double b = 2 * tuple::dot(r.vector, sphere_to_ray);
        double c = tuple::dot(sphere_to_ray, sphere_to_ray) - 1;
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0)
            return {};
        
        double t0 = (-b - sqrt(discriminant)) / (2 * a);
        double t1 = (-b + sqrt(discriminant)) / (2 * a);
        return {Intersection(s, t0), Intersection(s, t1)};
    }
} // namespace intersection