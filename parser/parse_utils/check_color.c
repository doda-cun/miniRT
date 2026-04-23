/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:28:19 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:43:51 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_color(t_color color, t_scene *scene)
{
	if (color.r < 0 || color.r > 255
		|| color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255)
	{
		scene->parser.error = 1;
		scene->parser.error_msg = "Color values must be between 0 and 255\n";
		return ;
	}
}
