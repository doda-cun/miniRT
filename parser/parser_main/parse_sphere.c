/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 16:42:46 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/13 17:02:18 by lderks        ########   odam.nl         */
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
	sphere.radius = safe_atof(parts[2]);	//we get Diameter!!
	sphere.color = parse_color(parts[3]);
	free_split(parts);
	scene->sphere[scene->parser.sphere_count++] = sphere;
}
