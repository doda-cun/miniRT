/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:33:27 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/20 18:41:51 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "shape.h"
#include "vectors.h"

static t_vector	get_cylinder_normal(t_cylinder *cylinder,
				t_intersection *intersection, t_point hit_point)
{
	t_vector	hit_to_base;
	float		projection;

	if (intersection->hit_cap)
	{
		if (intersection->hit_cap)
		{
			if (dot_product(cylinder->axis, intersection->ray.direction) < 0)
				return (cylinder ->axis);
			return (v_new_negative(cylinder->axis));
		}
	}
	hit_to_base = v_new_subtraction(hit_point, cylinder->center);
	projection = dot_product(hit_to_base, cylinder->axis);
	return (v_normalized(v_new_subtraction(hit_to_base,
				v_new_multiply_float(cylinder->axis, projection))));
}

t_color	get_cylinder_color(t_cylinder *cylinder, t_intersection *intersection)
{
	t_point		hit_point;
	t_vector	normal;
	t_vector	light_dir;
	double		diffuse;

	hit_point = v_new_addition(intersection->ray.origin,
			v_new_multiply_float(intersection->ray.direction,
				intersection->length));
	normal = get_cylinder_normal(cylinder, intersection, hit_point);
	light_dir = v_normalized(v_new_subtraction(
				intersection->scene->light.pos, hit_point));
	diffuse = dot_product(normal, light_dir)
		* intersection->scene->light.brightness;
	if (diffuse < 0)
		diffuse = 0;
	if (is_in_shadow(intersection->scene, hit_point, normal))
		diffuse = 0;
	return (apply_lighting(cylinder->color,
			intersection->scene->ambient, diffuse));
}
/*we need to know the normal to calculate the diffuse lighting.
For a cylinder is trickier since the normal is different depending
on where the ray hits
----Body/side-> normal points outward from the axis
----Cap -> normal points straigh up or down along the axis*/

/*projection = "how much of the vector goes along the axis direction".
Physically:

If the hit point is exactly at the center height → proj is small
If the hit point is near the top → proj is large (close to cylinder->height)
If the hit point is near the bottom → proj is small (close to 0)*/

/*hit to base is the vector from the cylinders center to the hit point*/
