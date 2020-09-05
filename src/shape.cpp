#include "shape.hpp"

namespace shape
{
int global_id = 0;

Shape::Shape(void)
    : empty(true)
    , id(global_id++)
    , transform(matrix::Matrix())
    , material(shades::Material())
{}

Shape::Shape(matrix::Matrix transform_, shades::Material material_)
    : empty(false)
    , id(global_id++)
    , transform(transform_)
    , material(material_)
{}

Shape::~Shape(void) {}

const int Shape::get_id(void) { return id; }
const matrix::Matrix Shape::get_transform(void) { return transform; }
const shades::Material Shape::get_material(void) { return material; }

void Shape::set_transform(matrix::Matrix m) { transform = m; }
void Shape::set_material(shades::Material m) { material = m; }

// tuple::Tuple Shape::normal(tuple::Tuple point) { return tuple::Tuple(0, 0, 0, 0); }

bool is_same_shape_object(Shape a, Shape b) { return a.get_id() == b.get_id(); }

} // namespace shape