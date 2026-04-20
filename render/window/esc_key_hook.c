/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:47:05 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/09 18:49:32 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "render.h"

int	esc_key_hook(int keycode, void *param)
{
	if (keycode == 65307)
		return (close_window(param));
	return (0);
}
