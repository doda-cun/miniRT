/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_plane_intersect.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/02 14:01:06 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/09 14:25:26 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

int	plane_full_intersect(t_shape *shape, t_intersection *intersection)
{
	t_plane	*plane = (t_plane *)shape;			//cast function pointer so it regocnizes full struct

	float		dot_product_normal;
	t_vector	origin_to_plane;
	float		length;
	
	dot_product_normal = dot_product(intersection->ray.direction, plane->normal);
	if (dot_product_normal == 0.0f)											//ray runs parallel (equal) to the plane
		return (0);
	
	origin_to_plane = v_new_subtraction(plane->point, intersection->ray.origin);
	length = dot_product(origin_to_plane, plane->normal) / dot_product_normal;
	
	if (length <= RAY_T_MIN || length >= intersection->length)				//avoid self-intersection and only keep closest length / t to the camera. 
		return (0);
	
	intersection->length = length;
	intersection->shape = shape;
	intersection->color = plane->color;
	return (1);
}

int	plane_single_intersect(t_shape *shape, const t_ray *ray)
{
	t_plane	*plane;
	plane = (t_plane *)shape;

	t_vector	origin_to_plane;
	float		dot_product_normal;
	float		length;
	
	dot_product_normal = dot_product(ray->direction, plane->normal);
	if (dot_product_normal == 0.0f)
		return (0);
	origin_to_plane = v_new_subtraction(plane->point, ray->origin);
	length = dot_product(origin_to_plane, plane->normal) / dot_product_normal;
	if (length <= RAY_T_MIN || length >= ray->t_max)
		return (0);
	return (1);
}
