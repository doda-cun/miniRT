/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:24:49 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/24 19:29:39 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// t_color	parse_color(char *str, t_scene *scene)
// {
// 	char	**parts;
// 	t_color	color;

// 	ft_memset(&color, 0, sizeof(t_color));
// 	parts = ft_split(str, ',');
// 	check_parts(parts, 3, scene);
// 	if (scene->parser.error)
// 	{
// 		free_split(parts);
// 		return (color);
// 	}
// 	check_numeric(parts[0], scene);
// 	check_numeric(parts[1], scene);
// 	check_numeric(parts[2], scene);
// 	color.r = safe_atof(parts[0], scene);
// 	color.g = safe_atof(parts[1], scene);
// 	color.b = safe_atof(parts[2], scene);
// 	free_split(parts);
// 	check_color(color, scene);
// 	return (color);
// }

t_color	parse_color(char *str, t_scene *scene)
{
	char	**parts;
	t_color	color;

	ft_memset(&color, 0, sizeof(t_color));
	parts = ft_split(str, ',');
	if (parts_error(parts, 3, scene))
		return (color);
	check_numeric(parts[0], scene);
	check_numeric(parts[1], scene);
	check_numeric(parts[2], scene);
	color.r = safe_atof(parts[0], scene);
	color.g = safe_atof(parts[1], scene);
	color.b = safe_atof(parts[2], scene);
	free_split(parts);
	check_color(color, scene);
	return (color);
}
