#ifndef TEST_HPP_
#define TEST_HPP_

namespace test_canvas
{
void test_canvas(void);
void test_canvas_creation(void);
void test_ppm(void);
} // namespace test_canvas

namespace test_colour
{
void test_colour(void);
void test_colour_rgb(void);
void test_colour_add(void);
void test_colour_minus(void);
void test_colour_scalar_multiply(void);
void test_colour_multiply(void);
} // namespace test_colour

namespace test_intersection
{
void test_intersection(void);
void test_intersection_creation(void);
void test_intersection_list(void);
void test_intersection_object(void);
void test_positive_hits(void);
void test_both_hits(void);
void test_negative_hits(void);
void test_hits(void);
} // namespace test_intersection

namespace test_matrix
{
void test_matrix(void);
void test_matrix_creation(void);
void test_2x2_matrix(void);
void test_3x3_matrix(void);
void test_matrix_equality(void);
void test_matrix_multiplication(void);
void test_tuple_multiplication(void);
void test_identity_matrix(void);
void test_transpose(void);
void test_determinant(void);
void test_submatrix(void);
void test_minor(void);
void test_cofactor(void);
void test_extra_cofactor(void);
void test_invertibility(void);
void test_matrix_inverse(void);
void test_further_matrix_inverse(void);
void test_matrix_inverse_proof(void);
} // namespace test_matrix

namespace test_matrix_transform
{
void test_matrix_transform(void);
void test_matrix_translation(void);
void test_matrix_reverse_translation(void);
void test_matrix_vector_translation(void);
void test_matrix_point_scaling(void);
void test_matrix_vector_scaling(void);
void test_matrix_reverse_scaling(void);
void test_matrix_reflection(void);
void test_matrix_rotate_x(void);
void test_matrix_rotate_y(void);
void test_matrix_rotate_z(void);
void test_matrix_shear(void);
void test_matrix_chain_transforms(void);
} // namespace test_matrix_transform

namespace test_ray
{
void test_ray(void);
void test_ray_creation(void);
void test_point_on_ray(void);
void test_sphere_ray_intersection(void);
} // namespace test_ray

namespace test_ray_transform
{
void test_ray_transform(void);
void test_ray_translation(void);
void test_ray_scaling(void);
void test_sphere_transform(void);
void test_scaled_sphere_intersection(void);
} // namespace test_ray_transform

namespace test_scene
{
void test_scene(void);
void test_empty_world(void);
void test_default_world(void);
void test_world_ray_intersection(void);
} // namespace test_scene

namespace test_shades
{
void test_shades(void);
void test_sphere_normal(void);
void test_transformed_sphere_normal(void);
void test_reflect(void);
void test_point_light(void);
void test_material(void);
void test_lighting(void);
} // namespace test_shades

namespace test_tuple
{
void test_tuple(void);
void test_tuple_point(void);
void test_tuple_vector(void);
void test_is_equal_value(void);
void test_is_equal_tuple(void);
void test_add(void);
void test_minus_point(void);
void test_minus_vector_point(void);
void test_minus_vector(void);
void test_negate(void);
void test_scalar_multiply(void);
void test_scalar_divide(void);
void test_magnitude(void);
void test_normalise(void);
void test_dot_product(void);
void test_cross_product(void);
} // namespace test_tuple

#endif // TEST_HPP_
