/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_shapes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 14:51:58 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/20 13:48:30 by lderks        ########   odam.nl         */
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
	if (s->parser.shape_count == 0)
	{
		write(2, "Error\nMinimum of 1 shape per scene\n", 35);
		exit(1);	
	}
}
