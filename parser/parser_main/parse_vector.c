/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:32:41 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:29:03 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_vector	parse_vector(char *str, t_scene *scene)
{
	char		**parts;
	t_vector	vec;

	parts = ft_split(str, ',');
	check_parts(parts, 3, scene);
	check_numeric(parts[0], scene);
	check_numeric(parts[1], scene);
	check_numeric(parts[2], scene);
	vec.x = safe_atof(parts[0], scene);
	vec.y = safe_atof(parts[1], scene);
	vec.z = safe_atof(parts[2], scene);
	free_split(parts);
	return (vec);
}
