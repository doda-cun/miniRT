/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:42:27 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/24 19:43:50 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	strip_newline(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i >= 0 && (line[i] == '\n' || line[i] == '\t'
			|| line[i] == '\r' || line[i] == ' '))
	{
		line[i] = '\0';
		i--;
	}
}

void	parse_line(char *line, t_scene *scene)
{
	strip_newline(line);
	if (line[0] == 'A' && line[1] == ' ')
		parse_ambient(line, scene);
	else if (line[0] == 'C' && line[1] == ' ')
		parse_camera(line, scene);
	else if (line[0] == 'L' && line[1] == ' ')
		parse_light(line, scene);
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		parse_sphere(line, scene);
	else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		parse_plane(line, scene);
	else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		parse_cylinder(line, scene);
	else if (line[0] != '\n' && line[0] != '\0')
	{
		scene->parser.error = 1;
		scene->parser.error_msg = "Unknown identifier in scene file\n";
	}
}
