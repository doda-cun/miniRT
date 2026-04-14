/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_inter.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/26 18:02:08 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/03 14:02:45 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"
#include "rays.h"

t_intersection	i_create_default(void)
{
	t_intersection	intersection;

	intersection.ray = ray_c_default();
	intersection.length = RAY_T_MAX;
	intersection.shape = NO_HIT;
	return (intersection);
}

t_intersection	i_create_from_ray(t_ray ray)
{
	t_intersection	intersection;

	intersection.ray = ray_c_new(ray.origin, ray.direction, ray.t_max);
	intersection.length = RAY_T_MAX;
	intersection.shape = NO_HIT;
	return (intersection);
}
