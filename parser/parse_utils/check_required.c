/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_required.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 19:25:34 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/09 15:02:59 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_required(t_scene *scene)
{
	if (!scene->parser.has_ambient)
	{
		write(2, "Error\nMissing ambient light\n", 28);
		exit (1);
	}
	if (!scene->parser.has_camera)
	{
		write(2, "Error\nMissing camera\n", 21);
		exit (1);
	}
	if (!scene->parser.has_light)
	{
		write(2, "Error\nMissing light\n", 20);
		exit(1);
	}
	check_count_shapes(scene);		//added
}
