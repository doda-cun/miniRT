/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder_intersect.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 14:09:46 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/13 16:41:10 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

static int	check_body_candidates(t_cylinder *cylinder, t_intersection *intersection,
							t_cylinder_math *c_math)
{
	if (c_math->discriminant < 0.0f || c_math->a == 0.0f)
		return (0);
	c_math->t_near = (-c_math->b - sqrtf(c_math->discriminant)) / (2.0f * c_math->a);
	c_math->t_far = (-c_math->b + sqrtf(c_math->discriminant)) / (2.0f * c_math->a);
	if (check_body_hit(cylinder, intersection, c_math->t_near))
		return (1);
	if (check_body_hit(cylinder, intersection, c_math->t_far))
		return (1);
	return (0);
}
 
static int	check_body_hit(t_cylinder *cylinder, t_intersection *intersection, float t)
{
	t_point		hit;
	t_vector	hit_to_base;
	float		proj;
 
	if (t <= RAY_T_MIN || t >= intersection->length)
		return (0);
	hit = ray_calculate_length(&intersection->ray, t);
	hit_to_base = v_new_subtraction(hit, cylinder->center);
	proj = dot_product(hit_to_base, cylinder->axis);
	if (proj < 0.0f || proj > cylinder->height)		// ray between 0 and height
		return (0);
	intersection->length = t;
	intersection->shape = (t_shape *)cylinder;
	intersection->color = cylinder->color;
	return (1);
}

static int	check_caps(t_cylinder *cylinder, t_intersection *intersection)
{
	t_point	top_center;
	int		hit;

	hit = 0;
	top_center = v_new_addition(cylinder->center,
			v_new_multiply_float(cylinder->axis, cylinder->height));
	if (check_cap_hit(cylinder, intersection, cylinder->center))
		hit = 1;
	if (check_cap_hit(cylinder, intersection, top_center))
		hit = 1;
	return (hit);
}

static int	check_cap_hit(t_cylinder *cylinder, t_intersection *intersection,
							t_point cap_center)
{
	float		dDotN;
	t_vector	origin_to_cap;
	float		t;
	t_point		hit;
	t_vector	hit_to_cap;
 
	dDotN = dot_product(intersection->ray.direction, cylinder->axis);
	if (dDotN == 0.0f) //ray runs parallel to cap of cylinder, no hit
		return (0);
	origin_to_cap = v_new_subtraction(cap_center, intersection->ray.origin);
	t = dot_product(origin_to_cap, cylinder->axis) / dDotN;
	if (t <= RAY_T_MIN || t >= intersection->length)
		return (0);
	hit = ray_calculate_length(&intersection->ray, t);
	hit_to_cap = v_new_subtraction(hit, cap_center);	
	if (dot_product(hit_to_cap, hit_to_cap) > squared(cylinder->radius))
		return (0);				//check hit point is inside the disc (circle)
	intersection->length = t;
	intersection->shape = (t_shape *)cylinder;
	intersection->color = cylinder->color;
	return (1);
}
 
int	cylinder_full_intersect(t_shape *shape, t_intersection *intersection)
{
	t_cylinder		*cylinder;
	t_cylinder_math	c_math;
	int				hit;
 
	cylinder = (t_cylinder *)shape;
	set_body_math(cylinder, intersection, &c_math);
	hit = check_body_candidates(cylinder, intersection, &c_math);
	if (check_caps(cylinder, intersection))
		hit = 1;
	return (hit);
}