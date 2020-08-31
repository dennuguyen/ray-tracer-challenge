#ifndef INTERSECTION_HPP_
#define INTERSECTION_HPP_

#include "ray.hpp"
#include "shape.hpp"
#include "sphere.hpp"

namespace intersection
{
    struct Intersection
    {
        Intersection(void);
        Intersection(shape::Shape obj_, double t_);
        ~Intersection(void);

        bool empty;
        shape::Shape obj;
        double t;
    };

    bool is_same_intersection(Intersection a, Intersection b);
    inline bool operator==(Intersection a, Intersection b) { return is_same_intersection(a, b); };

    Intersection hit(std::vector<Intersection> v);
    std::vector<Intersection> intersect(shape::Sphere s, ray::Ray r);
} // namespace intersection

#endif // INTERSECTION_HPP_
