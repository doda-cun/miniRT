/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_single_intersect.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:25:11 by lderks            #+#    #+#             */
/*   Updated: 2026/04/20 18:34:59 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

static int	check_body_hit_s(t_cylinder *cylinder, const t_ray *ray, float t)
{
	t_point		hit;
	t_vector	hit_to_base;
	float		proj;

	if (t <= RAY_T_MIN || t >= ray->t_max)
		return (0);
	hit = ray_calculate_length(ray, t);
	hit_to_base = v_new_subtraction(hit, cylinder->center);
	proj = dot_product(hit_to_base, cylinder->axis);
	if (proj < 0.0f || proj > cylinder->height)
		return (0);
	return (1);
}

static int	check_body_candidates_s(t_cylinder *cylinder, const t_ray *ray,
				t_cylinder_math *c_math)
{
	if (c_math->discriminant < 0.0f || c_math->a == 0.0f)
		return (0);
	c_math->t_near = (-c_math->b - sqrtf(c_math->discriminant))
		/ (2.0f * c_math->a);
	c_math->t_far = (-c_math->b + sqrtf(c_math->discriminant))
		/ (2.0f * c_math->a);
	if (check_body_hit_s(cylinder, ray, c_math->t_near))
		return (1);
	if (check_body_hit_s(cylinder, ray, c_math->t_far))
		return (1);
	return (0);
}

static int	check_cap_hit_s(t_cylinder *cylinder, const t_ray *ray,
				t_point cap_center)
{
	float		d_dot_n;
	t_vector	origin_to_cap;
	float		t;
	t_point		hit;
	t_vector	hit_to_cap;

	d_dot_n = dot_product(ray->direction, cylinder->axis);
	if (d_dot_n == 0.0f)
		return (0);
	origin_to_cap = v_new_subtraction(cap_center, ray->origin);
	t = dot_product(origin_to_cap, cylinder->axis) / d_dot_n;
	if (t <= RAY_T_MIN || t >= ray->t_max)
		return (0);
	hit = ray_calculate_length(ray, t);
	hit_to_cap = v_new_subtraction(hit, cap_center);
	if (dot_product(hit_to_cap, hit_to_cap) > squared(cylinder->radius))
		return (0);
	return (1);
}

static int	check_caps_s(t_cylinder *cylinder, const t_ray *ray)
{
	t_point	top_center;

	top_center = v_new_addition(cylinder->center,
			v_new_multiply_float(cylinder->axis, cylinder->height));
	if (check_cap_hit_s(cylinder, ray, cylinder->center))
		return (1);
	if (check_cap_hit_s(cylinder, ray, top_center))
		return (1);
	return (0);
}

int	cylinder_single_intersect(t_shape *shape, const t_ray *ray)
{
	t_cylinder		*cylinder;
	t_cylinder_math	c_math;

	cylinder = (t_cylinder *)shape;
	set_cylinder_single_math(cylinder, ray, &c_math);
	if (check_body_candidates_s(cylinder, ray, &c_math))
		return (1);
	if (check_caps_s(cylinder, ray))
		return (1);
	return (0);
}
