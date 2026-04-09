/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/02 13:03:28 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/09 17:37:29 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
#define SHAPE_H

#include "structs.h"
#include "intersections.h"

typedef int (*t_full_intersect_fp)(struct t_shape *shape, t_intersection *intersection);
typedef int (*t_single_intersect_fp)(struct t_shape *shape, const t_ray *ray);

// Intersection math
int	plane_full_intersect(t_shape *shape, t_intersection *intersection);
int	plane_single_intersect(t_shape *shape, const t_ray *ray);
int	sphere_full_intersect(t_shape *shape, t_intersection *intersection);
int	sphere_single_intersect(t_shape *shape, const t_ray *ray);
int	shapeset_full_intersect(t_shapeset *set, t_intersection *intersection);

// Create
t_plane		*plane_create(t_point point, t_vector normal);
t_sphere 	*sphere_create(t_point centre, float radius);

#endif