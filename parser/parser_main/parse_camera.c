/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:19:54 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:59:45 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_camera(char *line, t_scene *scene)
{
	char	**parts;

	if (scene->parser.has_camera)
	{
		scene->parser.error = 1;
		scene->parser.error_msg = "Camera defined twice.\n";
		return ;
	}
	parts = ft_split (line, ' ');
	check_parts(parts, 4, scene);
	scene->camera.pos = parse_vector(parts[1], scene);
	scene->camera.dir = parse_normal(parts[2], scene);
	scene->camera.fov = safe_atoi(parts[3], scene);
	if (scene->camera.fov == 0)
		scene->camera.fov = 1;
	else if (scene->camera.fov == 180)
		scene->camera.fov = 179;
	check_fov(scene->camera.fov, scene);
	free_split(parts);
	scene->parser.has_camera = 1;
}
