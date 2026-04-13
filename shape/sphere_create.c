/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_sphere_create.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/02 14:03:07 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/09 14:45:54 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_sphere *sphere_create(t_point centre, float radius)
{
	t_sphere	*sphere;
	sphere = malloc(sizeof(t_sphere));
	sphere->shape.type = SPHERE;
	sphere->shape.full_intersection = &sphere_full_intersect;
	sphere->shape.single_intersection = &sphere_single_intersect;
	sphere->centre = centre;
	sphere->radius = radius;
	return (sphere);
}