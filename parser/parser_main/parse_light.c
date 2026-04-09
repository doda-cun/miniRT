/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_light.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 16:29:06 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/09 14:40:07 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_light(char *line, t_scene *scene)
{
	char	**parts;

	if (scene->parser.has_light)
	{
		write(2, "Error\nLight defined twice.\n", 27);
		exit(1);
	}
	parts = ft_split(line, ' ');
	check_parts(parts, 4);
	scene->light.pos = parse_vector(parts[1]);
	scene->light.brightness = safe_atof(parts[2]);
	check_ratio(scene->light.brightness);
	scene->light.color = parse_color(parts[3]);
	free_split(parts);
	scene->has_light = 1;
}
