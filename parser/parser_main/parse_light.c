/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:29:06 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:28:40 by doda-cun         ###   ########.fr       */
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
	check_parts(parts, 4, scene);
	scene->light.pos = parse_vector(parts[1], scene);
	scene->light.brightness = safe_atof(parts[2], scene);
	check_ratio(scene->light.brightness, scene);
	scene->light.color = parse_color(parts[3], scene);
	free_split(parts);
	scene->parser.has_light = 1;
}
