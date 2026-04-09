/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   r_create.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/26 15:50:25 by lderks        #+#    #+#                 */
/*   Updated: 2026/03/26 18:13:18 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_ray	ray_c_default()
{
	t_ray	ray;
	
	ray.origin = vec_c_xyz(0.0, 0.0, 0.0);
	ray.direction = vec_c_default();
	ray.t_max = (RAY_T_MAX);
	return (ray);
}

t_ray	ray_copy(t_ray ray)				//del -> t_ray copy = ray does the same thing
{
	t_ray	copy;
	
	copy.origin = ray.origin;
	copy.direction = ray.direction;
	copy.t_max = ray.t_max;
	return (copy);
}

t_ray	ray_c_new(t_point origin, t_vector direction, float t_max)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	ray.t_max = t_max;
	return (ray);
}