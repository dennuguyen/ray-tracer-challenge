#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include "matrix.hpp"

namespace shape
{
class Shape
{
public:
    Shape(void);
    ~Shape(void);

    const int get_id();
    const matrix::Matrix get_transform();
    
    void set_transform(matrix::Matrix m);

protected:
    bool empty;
    int id;
    matrix::Matrix transform;
};

bool is_same_shape_object(Shape a, Shape b);
inline bool operator==(Shape a, Shape b) { return is_same_shape_object(a, b); };

} // namespace shape

#endif // SHAPE_HPP_
