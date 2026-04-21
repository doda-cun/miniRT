/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_camera.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 18:19:54 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/21 17:18:10 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_camera(char *line, t_scene *scene)
{
	char	**parts;

	if (scene->parser.has_camera)
	{
		write(2, "Error\nCamera defined twice.\n", 28);
		exit(1);
	}
	parts = ft_split (line, ' ');
	check_parts(parts, 4);
	scene->camera.pos = parse_vector(parts[1]);
	scene->camera.dir = parse_normal(parts[2]);
	scene->camera.fov = safe_atoi(parts[3]);
	if (scene->camera.fov == 0)
		scene->camera.fov = 1;
	else if (scene->camera.fov == 180)
		scene->camera.fov = 179;
	check_fov(scene->camera.fov);
	free_split(parts);
	scene->parser.has_camera = 1;
}
