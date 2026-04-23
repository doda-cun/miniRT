/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:31:11 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:38:05 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_parts(char **parts, int expected, t_scene *scene)
{
	int	i;

	i = 0;
	while (parts[i])
		i++;
	if (i < expected)
	{
		scene->parser.error = 1;
		scene->parser.error_msg = "Missing fields in scene elements.\n";
		return ;
	}
}
