/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_line.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 17:42:27 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/06 17:50:32 by lderks        ########   odam.nl         */
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
	//GNL returns the string with \n this breaks the parser.
	if (line[0] == 'A')
		parse_ambient(line, scene);
	else if (line[0] == 'C')
		parse_camera(line, scene);
	else if (line[0] == 'L')
		parse_light(line, scene);
	else if (line[0] == 's' && line[1] == 'p')
		parse_sphere(line, scene);
	else if (line[0] == 'p' && line[1] == 'l')
		parse_plane(line, scene);
	else if (line[0] == 'c' && line[1] == 'y')
		parse_cylinder(line, scene);
	else if (line[0] != '\n' && line[0] != '\0')
	{
		write(2, "Error\nUnknown element in scene file\n", 36);
		exit(1);
	}
}
