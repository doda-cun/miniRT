/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 18:24:49 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/06 17:51:17 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_color	parse_color(char *str)
{
	char	**parts;
	t_color	color;

	parts = ft_split(str, ',');
	check_parts(parts, 3);
	check_numeric(parts[0]);
	check_numeric(parts[1]);
	check_numeric(parts[2]);
	color.r = ft_atoi(parts[0]);
	color.g = ft_atoi(parts[1]);
	color.b = ft_atoi(parts[2]);
	free_split(parts);
	check_color(color);
	return (color);
}
