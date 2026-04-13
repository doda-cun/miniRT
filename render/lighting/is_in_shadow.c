/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:52:37 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/13 18:30:48 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "shape.h"
#include "vectors.h"

int	is_in_shadow(t_scene *scene, t_point hit_point, t_vector normal)
{
	t_ray		shadow_ray;
	t_vector	light_dir;
	float		light_dist;

	light_dir = v_new_subtraction(scene->light.pos, hit_point);
	light_dist = length_square_r(light_dir);
	light_dir = v_normalized(light_dir);
	shadow_ray.origin = v_new_addition(hit_point,
			v_new_multiply_float(normal, 0.001f));
	shadow_ray.direction = light_dir;
	shadow_ray.t_max = light_dist;
	return (shapeset_single_intersect(&scene->shapeset, &shadow_ray));
}
/*it builds the shadow ray and asks the shapeset, then passes the yes/no
back to the color functions which decide how bright the pixel should be.*/
