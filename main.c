/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/09 17:31:00 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/21 12:13:59 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "render.h"
#include "parser.h"
#include "shape.h"
#include <stdio.h>

static void	mlx_setup(t_mlx *mlx);
static void	mlx_image_setup(t_mlx *mlx);

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
	mlx_image_setup(mlx);
}

static void	mlx_image_setup(t_mlx *mlx)
{
	mlx->image.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->image.img)
	{
		write(2, "Error\nImage creation failed\n", 28);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit (1);
	}
	mlx->image.addr = mlx_get_data_addr(mlx->image.img,
			&mlx->image.bits_per_pixel,
			&mlx->image.line_length,
			&mlx->image.endian);
	if (!mlx->image.addr)
	{
		write(2, "Error\nImage buffer setup failed\n", 33);
		mlx_destroy_image(mlx->mlx, mlx->image.img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit (1);
	}
}
