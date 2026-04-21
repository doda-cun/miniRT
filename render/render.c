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

static void	image_put_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length
			+ x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render(t_mlx *mlx, t_scene *scene)
{
	int				x;
	int				y;
	int				pixel_color;
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
			pixel_color = 0;
			if (shapeset_full_intersect(&scene->shapeset, &intersection))
				pixel_color = color_to_hex(intersection.color);
			image_put_pixel(&mlx->image, x, y, pixel_color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.img, 0, 0);
}
