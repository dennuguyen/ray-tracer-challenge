#include "shape.hpp"

namespace shape
{
int global_id = 0;

Shape::Shape(void)
    : empty(true)
    , id(global_id++)
    , transform(matrix::Matrix(3, 3))
{}

Shape::~Shape(void) {}

const int Shape::get_id() { return id; }
const matrix::Matrix Shape::get_transform() { return transform; }
void Shape::set_transform(matrix::Matrix m) { transform = m; }
bool is_same_shape_object(Shape a, Shape b) { return a.get_id() == b.get_id(); }
} // namespace shape