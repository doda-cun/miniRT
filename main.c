/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:31:00 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/20 18:46:49 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "render.h"
#include "parser.h"
#include "shape.h"
#include <stdio.h>

static void	mlx_setup(t_mlx *mlx);

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
	parse_scene(argv[1], &scene);
	mlx_setup(&mlx);
	camera_init(&scene.camera);
	add_shapes_to_set(&scene);
	render(&mlx, &scene);
	mlx_key_hook(mlx.win, esc_key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

static void	mlx_setup(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		write(2, "Error\nmlx_init failed\n", 22);
		exit (1);
	}
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "miniRT");
	if (!mlx->win)
	{
		write(2, "Error\nWindow creation failed\n", 29);
		exit (1);
	}
}
