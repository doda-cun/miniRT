/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/02 13:03:28 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/14 14:30:24 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
#define SHAPE_H

#include "structs.h"
#include "intersections.h"
#include "vectors.h"
#include "rays.h"

// typedef int (*t_full_intersect_fp)(struct t_shape *shape, t_intersection *intersection);
// typedef int (*t_single_intersect_fp)(struct t_shape *shape, const t_ray *ray);

// Intersection math
int		plane_full_intersect(t_shape *shape, t_intersection *intersection);
int		plane_single_intersect(t_shape *shape, const t_ray *ray);
int		sphere_full_intersect(t_shape *shape, t_intersection *intersection);
int		sphere_single_intersect(t_shape *shape, const t_ray *ray);
int		shapeset_full_intersect(t_shapeset *set, t_intersection *intersection);
void	set_cylinder_math(t_cylinder *cylinder, t_intersection *intersection,
							t_cylinder_math *c_math);
int		cylinder_full_intersect(t_shape *shape, t_intersection *intersection);
void	set_cylinder_single_math(t_cylinder *cylinder, const t_ray *ray, 
							t_cylinder_math *c_math);
int		cylinder_single_intersect(t_shape *shape, const t_ray *ray);

// Setup
void	add_shapeset(t_shapeset *shapeset, t_shape *shape);
void	add_sphere_to_set(t_scene *scene, int i);
void	add_plane_to_set(t_scene *scene, int i);
void	add_cylinder_to_set(t_scene *scene, int i);
void	add_shapes_to_set(t_scene *scene);

#endif
