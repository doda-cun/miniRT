/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:12:44 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/21 15:29:31 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "shape.h"
#include "vectors.h"

t_color	get_plane_color(t_plane *plane, t_intersection *intersection)
{
	t_point		hit_point;
	t_vector	normal;
	t_vector	light_dir;
	double		diffuse;

	hit_point = v_new_addition(intersection->ray.origin,
			v_new_multiply_float(intersection->ray.direction,
				intersection->length));
	normal = plane->normal;
	if (dot_product(normal, intersection->ray.direction) > 0)
		normal = v_new_negative(normal);
	light_dir = v_normalized(v_new_subtraction(
				intersection->scene->light.pos, hit_point));
	diffuse = dot_product(normal, light_dir)
		* intersection->scene->light.brightness;
	if (diffuse < 0)
		diffuse = 0;
	if (is_in_shadow(intersection->scene, hit_point, plane->normal))
		diffuse = 0;
	return (apply_lighting(plane->color,
			intersection->scene->ambient, diffuse));
}

/* if statement flips the normal: if the normal and the
ray are pointing in the same general direction (both going forward),
flip the normal." */

/*Think of it like a piece of paper — if you look at it from the front,
the normal faces you. If you look at it from the back, the normal should
flip to still face you. This makes the plane look correctly
lit from both sides.*/
