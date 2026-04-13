/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:31:00 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/10 18:36:34 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "render.h"
#include "parser.h"
#include "shape.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_mlx	mlx;

	if (argc != 2)
	{
		write(2, "Error\nUsage: ./miniRT <scene.rt>\n", 33);
		return (1);
	}
	ft_memset(&scene, 0, sizeof(t_scene));
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
	{
		write(2, "Error\nmlx_init failed\n", 22);
		return (1);
	}
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "miniRT test");
	if (!mlx.win)
	{
		write(2, "Error\nWindow creation failed\n", 29);
		return (1);
	}
	parse_scene(argv[1], &scene);
	camera_init(&scene.camera);
	add_shapes_to_set(&scene);
	render(&mlx, &scene);
	mlx_key_hook(mlx.win, esc_key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx); //17 code for the red X
	mlx_loop(mlx.mlx);
//	free everything
	return (0);
}

// -> MLX SETUP

// MLX's mlx_pixel_put is notoriously slow when called per-pixel in a loop because it flushes to the display each call.
// For a raytracer this will be very visible.
// The standard solution is to use an image buffer instead — mlx_new_image;
// write pixels with mlx_put_pixel_to_image into an off-screen buffer;
// then display the whole frame with mlx_put_image_to_window once done.

// That said, for getting something on screen initially, mlx_pixel_put works fine.
