/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_shapes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 14:51:58 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/09 14:59:55 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_count_shapes(t_scene *s)
{
	s.shape_count = s.shpere_count + s.cylinder_count + s.plane_count;
	if (shape_count > MAX_SHAPES)
	{
		write(2, "Error\nSurpassing allowed amount of shapes\n", 42);
		exit(1);
	}
}