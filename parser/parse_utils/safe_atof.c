/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:53:57 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:46:08 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	safe_atof(char *str, t_scene *scene)
{
	double	value;

	check_numeric(str, scene);
	if (ft_strlen(str) > 10)
	{
		scene->parser.error = 1;
		scene->parser.error_msg = "Value out of range\n";
		return (0);
	}
	value = ft_atof(str);
	if (value > INT_MAX || value < INT_MIN)
	{
		scene->parser.error = 1;
		scene->parser.error_msg = "Int value out of range\n";
		return (0);
	}
	return (value);
}
