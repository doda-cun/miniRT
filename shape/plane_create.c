/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_plane_create.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/02 14:02:49 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/09 14:45:20 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_plane	*plane_create(t_point point, t_vector normal)
{
	t_plane *plane;							//have a check for camera looking up
	plane = malloc(sizeof(t_plane));		//need to free
	plane->shape.type = PLANE;
	plane->shape.full_intersection = &plane_full_intersect;
	plane->shape.single_intersection = &plane_single_intersect;
	plane->point = point;
	plane->normal = normal;					// Needs to be made with the normal vector creator
	return (plane);
}