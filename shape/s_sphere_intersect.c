/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sphere_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:01:34 by lderks            #+#    #+#             */
/*   Updated: 2026/04/10 18:35:30 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "vectors.h"
#include <stdio.h>


int	sphere_full_intersect(t_shape *shape, t_intersection *intersection)
{
	t_sphere *sphere;
	sphere = (t_sphere *)shape;

	t_ray	local_ray;
	local_ray = intersection->ray;
	local_ray.origin = v_new_subtraction(local_ray.origin, sphere->centre);

	float	a = length_square(local_ray.direction);
	float	b = 2 * dot_product(local_ray.direction, local_ray.origin);
	float	c = length_square(local_ray.origin) - squared(sphere->radius);

	float discriminant = squared(b) - 4 * a * c;
	if (discriminant < 0.0f)
		return (0);

	float length_1 = (-b - sqrtf(discriminant)) / (2 * a);
	float length_2 = (-b + sqrtf(discriminant)) / (2 * a);

	if (length_1 > RAY_T_MIN && length_1 < intersection->length)
		intersection->length = length_1;
	else if (length_2 > RAY_T_MIN && length_2 < intersection->length)
		intersection->length = length_2;
	else
		return (0);

	intersection->shape = shape;
	intersection->color = sphere->color;

	return (1);
}									//fuctions need to be made norminette proof

int	sphere_single_intersect(t_shape *shape, const t_ray *ray)
{
	t_sphere	*sphere;
	sphere = (t_sphere *)shape;


	t_ray	local_ray;
	local_ray = *ray;
	local_ray.origin = v_new_subtraction(local_ray.origin, sphere->centre);

	float	a = length_square(local_ray.direction);
	float	b = 2 * dot_product(local_ray.direction, local_ray.origin);
	float	c = length_square(local_ray.origin) - squared(sphere->radius);

	float	discriminant = squared(b) - 4 * a * c;
	if (discriminant < 0.0f)
		return (0);

	float	length_1;
	float	length_2;

	length_1 = (-b - sqrtf(discriminant)) / (2 * a);
	if (length_1 > RAY_T_MIN && length_1 < ray->t_max)
		return (1);
	length_2 = (-b + sqrtf(discriminant)) / (2 * a);
	if (length_2 > RAY_T_MIN && length_2 < ray->t_max)
		return (1);
	return (0);
}
