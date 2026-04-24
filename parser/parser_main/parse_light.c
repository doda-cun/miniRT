/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:29:06 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:59:56 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_light(char *line, t_scene *scene)
{
	char	**parts;

	if (scene->parser.has_light)
	{
		scene->parser.error = 1;
		scene->parser.error_msg = "Light defined twice.\n";
		return ;
	}
	parts = ft_split(line, ' ');
	if (parts_error(parts, 4, scene))
		return ;
	scene->light.pos = parse_vector(parts[1], scene);
	scene->light.brightness = safe_atof(parts[2], scene);
	check_ratio(scene->light.brightness, scene);
	scene->light.color = parse_color(parts[3], scene);
	free_split(parts);
	scene->parser.has_light = 1;
}
