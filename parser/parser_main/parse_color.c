/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:24:49 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/24 19:43:04 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_color	zero_color(void)
{
	t_color	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	return (color);
}

static int	init_color_parts(char *str, char ***parts, t_scene *scene)
{
	if (!str)
		return (missing_fields_error(scene));
	*parts = ft_split(str, ',');
	return (parts_error(*parts, 3, scene));
}

t_color	parse_color(char *str, t_scene *scene)
{
	char	**parts;
	t_color	color;

	color = zero_color();
	if (init_color_parts(str, &parts, scene))
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
