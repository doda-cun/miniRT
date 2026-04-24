/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:32:41 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/24 19:44:14 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_vector	zero_vector(void)
{
	t_vector	vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	return (vec);
}

static int	init_vector_parts(char *str, char ***parts, t_scene *scene)
{
	if (!str)
		return (missing_fields_error(scene));
	*parts = ft_split(str, ',');
	return (parts_error(*parts, 3, scene));
}

t_vector	parse_vector(char *str, t_scene *scene)
{
	char		**parts;
	t_vector	vec;

	vec = zero_vector();
	if (init_vector_parts(str, &parts, scene))
		return (vec);
	check_numeric(parts[0], scene);
	check_numeric(parts[1], scene);
	check_numeric(parts[2], scene);
	vec.x = safe_atof(parts[0], scene);
	vec.y = safe_atof(parts[1], scene);
	vec.z = safe_atof(parts[2], scene);
	free_split(parts);
	return (vec);
}
