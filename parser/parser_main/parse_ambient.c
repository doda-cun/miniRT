/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:12:08 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/24 19:42:29 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_ambient(char *line, t_scene *scene)
{
	char	**parts;

	if (scene->parser.has_ambient)
	{
		scene->parser.error = 1;
		scene->parser.error_msg = "Ambient light defined twice.\n";
		return ;
	}
	parts = ft_split(line, ' ');
	if (parts_error(parts, 3, scene))
		return ;
	scene->ambient.ratio = safe_atof(parts[1], scene);
	check_ratio(scene->ambient.ratio, scene);
	scene->ambient.color = parse_color(parts[2], scene);
	free_split(parts);
	scene->parser.has_ambient = 1;
}
