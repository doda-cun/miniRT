/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:42:46 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/14 13:13:55 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_sphere(char *line, t_scene *scene)
{
	char		**parts;
	t_sphere	sphere;

	parts = ft_split(line, ' ');
	check_parts(parts, 4);
	sphere.centre = parse_vector(parts[1]);
	sphere.radius = safe_atof(parts[2]) / 2.0f;
	sphere.color = parse_color(parts[3]);
	free_split(parts);
	scene->sphere[scene->parser.sphere_count++] = sphere;
}
