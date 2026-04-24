/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:31:11 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/24 19:41:06 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	missing_fields_error(t_scene *scene)
{
	scene->parser.error = 1;
	scene->parser.error_msg = "Missing fields in scene elements.\n";
	return (1);
}

void	check_parts(char **parts, int expected, t_scene *scene)
{
	int	i;

	if (!parts)
	{
		missing_fields_error(scene);
		return ;
	}
	i = 0;
	while (parts[i])
		i++;
	if (i != expected)
	{
		missing_fields_error(scene);
		return ;
	}
}

int	parts_error(char **parts, int expected, t_scene *scene)
{
	check_parts(parts, expected, scene);
	if (scene->parser.error)
	{
		free_split(parts);
		return (1);
	}
	return (0);
}
