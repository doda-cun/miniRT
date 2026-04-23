/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_line.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 17:42:27 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/23 17:13:59 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	strip_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			return ;
		}
		i++;
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
		write(2, "Error\nUnknown element in scene file\n", 36);
		exit(1);
	}
}
