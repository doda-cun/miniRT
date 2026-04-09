/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_plane.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 16:48:36 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/09 14:40:36 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_plane(char *line, t_scene *scene)
{
	char	**parts;
	t_plane	plane;

	parts = ft_split(line, ' ');
	check_parts(parts, 4);
	plane.point = parse_vector(parts[1]);
	plane.normal = parse_normal(parts[2]);
	plane.color = parse_color(parts[3]);
	free_split(parts);
	scene->plane[scene->parser.plane_count++] = plane;
}
