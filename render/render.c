/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:26:04 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/20 18:46:15 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "render.h"
#include "shape.h"
#include <stdio.h>

void	render(t_mlx *mlx, t_scene *scene)
{
	int				x;
	int				y;
	t_ray			ray;
	t_intersection	intersection;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = camera_make_ray(&scene->camera, x, y);
			intersection = i_create_from_ray(ray);
			intersection.scene = scene;
			if (shapeset_full_intersect(&scene->shapeset, &intersection))
			{
				mlx_pixel_put(mlx->mlx, mlx->win, x, y,
					color_to_hex(intersection.color));
			}
			x++;
		}
		y++;
	}
}
