/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:06:32 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:36:52 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_vector	parse_normal(char *str, t_scene *scene)
{
	t_vector	vec;

	vec = parse_vector(str, scene);
	check_normal(vec.x, scene);
	check_normal(vec.y, scene);
	check_normal(vec.z, scene);
	return (vec);
}
