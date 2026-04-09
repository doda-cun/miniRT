/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_add_shape.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/06 19:29:03 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/09 14:48:22 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	add_shapeset(t_shapeset *shapeset, t_shape *shape)
{
	if (set_count >= MAX_SHAPES)
		return ;
	shapeset->shapes[shapeset->count] = shape;
	shapeset->count++;
}

void	add_shapes_to_set(t_scene *scene)
{
	add_shapeset(&scene->shapeset, &scene->plane);			// Need to normalize for plane and cylinder?
	scene->sphere->radius = scene->sphere->radius / 2.0f;	// MOVE!!! Diameter to radius (diameter / 2)
	add_shapeset(&scene->shapeset, &scene->sphere);
	add_shapeset(&scene->shapeset, &scene->cylinder);
}

//make this loops for extra shapes something like beneath

void    add_shapes_to_set(t_scene *scene)
{
    int i;

    scene->shapeset.count = 0;
    i = 0;
    while (i < scene->parser.plane_count)
    {
        scene->plane[i].normal = v_normalized(scene->plane[i].normal);
        shapeset_add(&scene->shapeset, (t_shape *)&scene->plane[i]);
        i++;
    }
    i = 0;
    while (i < scene->parser.sphere_count)
    {
        scene->sphere[i].radius = scene->sphere[i].radius / 2.0f;
        shapeset_add(&scene->shapeset, (t_shape *)&scene->sphere[i]);
        i++;
	}
    i = 0;
    while (i < scene->parser.cylinder_count)
    {
        scene->cylinder[i].axis = v_normalized(scene->cylinder[i].axis);
        shapeset_add(&scene->shapeset, (t_shape *)&scene->cylinder[i]);
        i++;
    }
}