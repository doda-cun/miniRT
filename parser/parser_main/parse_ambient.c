/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_ambient.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 18:12:08 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/23 18:52:37 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// void	parse_ambient(char *line, t_scene *scene)
// {
// 	char	**parts;

// 	if (scene->parser.has_ambient)
// 	{
// 		write(2, "Error\nAmbient light defined twice.\n", 34);
// 		exit(1);
// 	}
// 	parts = ft_split(line, ' ');
// 	check_parts(parts, 3);
// 	scene->ambient.ratio = safe_atof(parts[1]);
// 	check_ratio(scene->ambient.ratio);
// 	scene->ambient.color = parse_color(parts[2]);
// 	free_split(parts);
// 	scene->parser.has_ambient = 1;
// }

void	parse_ambient(char *line, t_scene *scene)
{
	char	**parts;
	
	if (scene->parser.has_ambient)
	{
		write(2, "Error\nAmbient light defined twice.\n", 34);
		exit(1);
	}
	parts = ft_split(line, ' ');
	check_parts(parts, 3, scene);
	scene->ambient.ratio = safe_atof(parts[1], scene);
	check_ratio(scene->ambient.ratio, scene);
	scene->ambient.color = parse_color(parts[2], scene);
	free_split(parts);
	scene->parser.has_ambient = 1;
}