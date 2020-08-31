#ifndef INTERSECTION_HPP_
#define INTERSECTION_HPP_

#include "shape.hpp"

namespace intersection
{
    struct Intersection
    {
        Intersection();
        Intersection(shape::Shape obj_, double t_);
        ~Intersection();

        bool empty;
        shape::Shape obj;
        double t;
    };

    bool is_same_intersection(Intersection a, Intersection b);
    bool is_hit(Intersection a, Intersection b);
    inline bool operator==(Intersection a, Intersection b) { return is_same_intersection(a, b); };
    inline bool operator<(Intersection a, Intersection b) { return is_hit(a, b); };

    Intersection hit(std::vector<Intersection> v);
    std::vector<Intersection> intersect(shape::Sphere s, ray::Ray r);
} // namespace intersection

#endif // INTERSECTION_HPP_
