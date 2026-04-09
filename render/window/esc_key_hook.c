/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:47:05 by doda-cun          #+#    #+#             */
/*   Updated: 2026/03/17 13:57:33 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	esc_key_hook(int keycode, void *param)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(((t_mlx *)param)->mlx, ((t_mlx *)param)->win);
		exit(0);
	}
	return (0);
}
