/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:51:39 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/14 13:15:43 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_cylinder(char *line, t_scene *scene)
{
	char		**parts;
	t_cylinder	cylinder;

	parts = ft_split(line, ' ');
	check_parts(parts, 6);
	cylinder.center = parse_vector(parts[1]);
	cylinder.axis = parse_normal(parts[2]);
	cylinder.radius = safe_atof(parts[3]) / 2.0f;	//now Diameter!
	cylinder.height = safe_atof(parts[4]);
	cylinder.color = parse_color(parts[5]);
	free_split(parts);
	scene->cylinder[scene->parser.cylinder_count++] = cylinder;
}
