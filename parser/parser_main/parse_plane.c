/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:48:36 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:37:03 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_plane(char *line, t_scene *scene)
{
	char	**parts;
	t_plane	plane;

	parts = ft_split(line, ' ');
	if (parts_error(parts, 4, scene))
		return ;
	plane.point = parse_vector(parts[1], scene);
	plane.normal = parse_normal(parts[2], scene);
	plane.color = parse_color(parts[3], scene);
	free_split(parts);
	scene->plane[scene->parser.plane_count++] = plane;
}
