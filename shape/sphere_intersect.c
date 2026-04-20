/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:01:34 by lderks            #+#    #+#             */
/*   Updated: 2026/04/20 18:43:32 by doda-cun         ###   ########.fr       */
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
