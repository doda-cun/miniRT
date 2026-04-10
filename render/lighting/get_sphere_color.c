/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:01:36 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/10 19:10:31 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "shape.h"
#include "vectors.h"

t_color	get_sphere_color(t_sphere *sphere, t_intersection *intersection)
{
	t_point		hit_point;
	t_vector	normal;
	t_vector	light_dir;
	double		diffuse;

	hit_point = v_new_addition(intersection->ray.origin,
			v_new_multiply_float(intersection->ray.direction,
				intersection->length));
	normal = v_normalized(v_new_subtraction(hit_point, sphere->centre));
	light_dir = v_normalized(v_new_subtraction(
				intersection->scene->light.pos, hit_point));
	diffuse = dot_product(normal, light_dir)
				* intersection->scene->light.brightness;
	if (diffuse < 0)
		diffuse = 0;
	return (apply_lighting(sphere->color,
			intersection->scene->ambient, diffuse));
}
