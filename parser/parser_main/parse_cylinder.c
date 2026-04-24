/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:51:39 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:36:45 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_cylinder(char *line, t_scene *scene)
{
	char		**parts;
	t_cylinder	cylinder;

	parts = ft_split(line, ' ');
	if (parts_error(parts, 6, scene))
		return ;
	cylinder.center = parse_vector(parts[1], scene);
	cylinder.axis = parse_normal(parts[2], scene);
	cylinder.radius = safe_atof(parts[3], scene) / 2.0f;
	cylinder.height = safe_atof(parts[4], scene);
	cylinder.color = parse_color(parts[5], scene);
	free_split(parts);
	scene->cylinder[scene->parser.cylinder_count++] = cylinder;
}
