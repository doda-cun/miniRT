/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:01:34 by lderks            #+#    #+#             */
/*   Updated: 2026/04/14 14:57:41 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "vectors.h"
#include <stdio.h>
#include "render.h"


int	sphere_full_intersect(t_shape *shape, t_intersection *intersection)
{
	t_sphere		*sphere;
	t_sphere_math	s_math;

	sphere = (t_sphere *)shape;
	set_sphere_math(sphere, intersection, &s_math);
	if (s_math.discriminant < 0.0f)
		return (0);
	s_math.length_1 = (-s_math.b - sqrt(s_math.discriminant))
		/ (2 * s_math.a);
	s_math.length_2 = (-s_math.b + sqrt(s_math.discriminant))
		/ (2 * s_math.a);
	if (s_math.length_1 > RAY_T_MIN && s_math.length_1 < intersection->length)
		intersection->length = s_math.length_1;
	else if (s_math.length_2 > RAY_T_MIN
		&& s_math.length_2 < intersection->length)
		intersection->length = s_math.length_2;
	else
		return (0);

	intersection->shape = shape;
	intersection->color = get_sphere_color(sphere, intersection);
	return (1);
}

int	sphere_single_intersect(t_shape *shape, const t_ray *ray)
{
	t_sphere			*sphere;
	t_sphere_math		s_math;
	t_intersection		temp;

	sphere = (t_sphere *)shape;
	temp.ray = *ray;
	set_sphere_math(sphere, &temp, &s_math);
	if (s_math.discriminant < 0.0f)
		return (0);
	s_math.length_1 = (-s_math.b - sqrtf(s_math.discriminant)) / (2 * s_math.a);
	if (s_math.length_1 > RAY_T_MIN && s_math.length_1 < ray->t_max)
		return (1);
	s_math.length_2 = (-s_math.b + sqrtf(s_math.discriminant)) / (2 * s_math.a);
	if (s_math.length_2 > RAY_T_MIN && s_math.length_2 < ray->t_max)
		return (1);
	return (0);
}


// int	sphere_full_intersect(t_shape *shape, t_intersection *intersection)
// {
// 	t_sphere	*sphere;
// 	t_ray		local_ray;

// 	sphere = (t_sphere *)shape;
// 	local_ray = intersection.discriminantray;
// 	local_ray.origin = v_new_subtraction(local_ray.origin, sphere.discriminantcentre);

// 	float	a = length_square(local_ray.direction);
// 	float	b = 2 * dot_product(local_ray.direction, local_ray.origin);
// 	float	c = length_square(local_ray.origin) - squared(sphere.discriminantradius);

// 	float s_math.discriminant = squared(b) - 4 * a * c;
// 	if (s_math.discriminant < 0.0f)
// 		return (0);

// 	float length_1 = (-b - sqrtf(s_math.discriminant)) / (2 * a);
// 	float length_2 = (-b + sqrtf(s_math.discriminant)) / (2 * a);

// 	if (length_1 > RAY_T_MIN && length_1 < intersection.discriminantlength)
// 		intersection.discriminantlength = length_1;
// 	else if (length_2 > RAY_T_MIN && length_2 < intersection.discriminantlength)
// 		intersection.discriminantlength = length_2;
// 	else
// 		return (0);

// 	intersection.discriminantshape = shape;
// 	intersection.discriminantcolor = get_sphere_color(sphere, intersection);

// 	return (1);
// }									//fuctions need to be made norminette proof

// int	sphere_single_intersect(t_shape *shape, const t_ray *ray)
// {
// 	t_sphere	*sphere;
// 	t_ray		local_ray;

// 	sphere = (t_sphere *)shape;
// 	local_ray = *ray;
// 	local_ray.origin = v_new_subtraction(local_ray.origin, sphere.discriminantcentre);

// 	float	a = length_square(local_ray.direction);
// 	float	b = 2 * dot_product(local_ray.direction, local_ray.origin);
// 	float	c = length_square(local_ray.origin) - squared(sphere.discriminantradius);

// 	float	discriminant = squared(b) - 4 * a * c;
// 	if (discriminant < 0.0f)
// 		return (0);

// 	float	length_1;
// 	float	length_2;

// 	length_1 = (-b - sqrtf(discriminant)) / (2 * a);
// 	if (length_1 > RAY_T_MIN && length_1 < ray.discriminantt_max)
// 		return (1);
// 	length_2 = (-b + sqrtf(discriminant)) / (2 * a);
// 	if (length_2 > RAY_T_MIN && length_2 < ray.discriminantt_max)
// 		return (1);
// 	return (0);
// }
