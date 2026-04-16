/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_shape.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/06 19:29:03 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/14 17:57:34 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "vectors.h"


void	add_shapeset(t_shapeset *shapeset, t_shape *shape)
{
	if (shapeset->count >= MAX_SHAPES)
		return ;
	shapeset->shapes[shapeset->count] = shape;
	shapeset->count++;
}

void	add_sphere_to_set(t_scene *scene, int i)
{
	scene->sphere[i].shape.full_intersection = sphere_full_intersect;
	scene->sphere[i].shape.single_intersection = sphere_single_intersect;
	scene->sphere[i].radius = scene->sphere[i].radius;
	add_shapeset(&scene->shapeset, (t_shape *)&scene->sphere[i]);
}

void	add_plane_to_set(t_scene *scene, int i)
{
	scene->plane[i].shape.full_intersection = plane_full_intersect;
	scene->plane[i].shape.single_intersection = plane_single_intersect;
	scene->plane[i].normal = v_normalized(scene->plane[i].normal);
	add_shapeset(&scene->shapeset, (t_shape *)&scene->plane[i]);
}

void	add_cylinder_to_set(t_scene *scene, int i)
{
	scene->cylinder[i].shape.full_intersection = cylinder_full_intersect;
	scene->cylinder[i].shape.single_intersection = cylinder_single_intersect;
	scene->cylinder[i].axis = v_normalized(scene->cylinder[i].axis);
	add_shapeset(&scene->shapeset, (t_shape *)&scene->cylinder[i]);
}

void	add_shapes_to_set(t_scene *scene)
{
	int		i;

	scene->shapeset.count = 0;
	i = 0;
	while (i < scene->parser.sphere_count)
		add_sphere_to_set(scene, i++);
	i = 0;
	while (i < scene->parser.plane_count)
		add_plane_to_set(scene, i++);
	i = 0;
	while (i < scene->parser.cylinder_count)
		add_cylinder_to_set(scene, i++);
}
