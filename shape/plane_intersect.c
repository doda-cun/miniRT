/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:01:06 by lderks            #+#    #+#             */
/*   Updated: 2026/04/14 14:53:18 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "vectors.h"
#include "render.h"

int	plane_full_intersect(t_shape *shape, t_intersection *intersection)
{
	//cast function pointer so it regocnizes full struct
	t_plane		*plane;
	float		dot_product_normal;
	t_vector	origin_to_plane;
	float		length;

	plane = (t_plane *)shape;
	dot_product_normal = dot_product(intersection->ray.direction,
			plane->normal);
	if (dot_product_normal == 0.0f)
	//ray runs parallel (equal) to the plane
		return (0);

	origin_to_plane = v_new_subtraction(plane->point, intersection->ray.origin);
	length = dot_product(origin_to_plane, plane->normal) / dot_product_normal;

	if (length <= RAY_T_MIN || length >= intersection->length)
	//avoid self-intersection and only keep closest length / t to the camera.
		return (0);
	intersection->length = length;
	intersection->shape = shape;
	intersection->color = get_plane_color(plane, intersection);
	return (1);
}

int	plane_single_intersect(t_shape *shape, const t_ray *ray)
{
	t_plane		*plane;
	t_vector	origin_to_plane;
	float		dot_product_normal;
	float		length;

	plane = (t_plane *)shape;
	dot_product_normal = dot_product(ray->direction, plane->normal);
	if (dot_product_normal == 0.0f)
		return (0);
	origin_to_plane = v_new_subtraction(plane->point, ray->origin);
	length = dot_product(origin_to_plane, plane->normal) / dot_product_normal;
	if (length <= RAY_T_MIN || length >= ray->t_max)
		return (0);
	return (1);
}
