/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_window.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 13:58:08 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/03 14:59:24 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	close_window(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (mlx->image.img)
		mlx_destroy_image(mlx->mlx, mlx->image.img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	exit(0);
	return (0);
}
