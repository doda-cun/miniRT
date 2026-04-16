/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:22:42 by lderks            #+#    #+#             */
/*   Updated: 2026/04/14 18:06:47 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "vectors.h"

t_ray	camera_make_ray(t_camera *cam, int x, int y)
{
	t_ray		ray;
	float		pixel_x;
	float		pixel_y;
	t_vector	direction;

	pixel_x = ((x - WIDTH / 2.0f) / (WIDTH / 2.0f)) * cam->half_w;
	pixel_y = -((y - HEIGHT / 2.0f) / (HEIGHT / 2.0f))
		* cam->half_h; /*flips it*/
	direction = v_new_addition(
			v_new_addition(
				v_new_multiply_float(cam->right, pixel_x),
				v_new_multiply_float(cam->up, pixel_y)), cam->dir);
	ray.origin = cam->pos;
	ray.direction = v_normalized(direction);
	return (ray);
}
