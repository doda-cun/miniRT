/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_normal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 19:06:32 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/06 19:01:07 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_vector	parse_normal(char *str)
{
	t_vector	vec;

	vec = parse_vector(str);
	check_normal(vec.x);
	check_normal(vec.y);
	check_normal(vec.z);
	return (vec);
}
