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
	mlx_destroy_window(((t_mlx *)param)->mlx, ((t_mlx *)param)->win);
	exit(0);
}
