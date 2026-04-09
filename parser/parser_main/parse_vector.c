/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_vec3.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 18:32:41 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/06 19:01:13 by lderks        ########   odam.nl         */
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
	vec.x = ft_atof(parts[0]);
	vec.y = ft_atof(parts[1]);
	vec.z = ft_atof(parts[2]);
	free_split(parts);
	return (vec);
}
