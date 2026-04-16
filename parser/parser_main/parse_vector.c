/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:32:41 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/16 17:46:18 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_vector	parse_vector(char *str)
{
	char		**parts;
	t_vector	vec;

	parts = ft_split(str, ',');
	check_parts(parts, 3);
	check_numeric(parts[0]);
	check_numeric(parts[1]);
	check_numeric(parts[2]);
	vec.x = safe_atof(parts[0]);
	vec.y = safe_atoi(parts[1]);
	vec.z = safe_atof(parts[2]);
	free_split(parts);
	return (vec);
}
