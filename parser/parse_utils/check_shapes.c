/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:51:58 by lderks            #+#    #+#             */
/*   Updated: 2026/04/09 18:33:42 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_count_shapes(t_scene *s)
{
	s->parser.shape_count = s->parser.sphere_count + s->parser.cylinder_count
		+ s->parser.plane_count;
	if (s->parser.shape_count > MAX_SHAPES)
	{
		write(2, "Error\nSurpassing allowed amount of shapes\n", 42);
		exit(1);
	}
}
