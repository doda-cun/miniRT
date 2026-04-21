/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_in_shadow.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 17:52:37 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/21 16:44:21 by lderks        ########   odam.nl         */
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
	float		bias;

	light_dir = v_new_subtraction(scene->light.pos, hit_point);
	light_dist = length_square_r(light_dir);
	light_dir = v_normalized(light_dir);
	normal = v_normalized(normal);
	if (dot_product(normal, light_dir) < 0.0f)
		normal = v_new_negative(normal);
	bias = RAY_T_MIN * 4.0f;
	shadow_ray.origin = v_new_addition(hit_point,
			v_new_multiply_float(normal, bias));
	shadow_ray.direction = light_dir;
	shadow_ray.t_max = light_dist - bias;
	if (shadow_ray.t_max <= RAY_T_MIN)
		return (0);
	return (shapeset_single_intersect(&scene->shapeset, &shadow_ray));
}
/*it builds the shadow ray and asks the shapeset, then passes the yes/no
back to the color functions which decide how bright the pixel should be.*/
