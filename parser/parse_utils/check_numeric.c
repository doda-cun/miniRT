/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numeric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:47:08 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:45:59 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_numeric(char *str, t_scene *scene)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != '.' && (str[i] < '0' || str[i] > '9'))
		{
			scene->parser.error = 1;
			scene->parser.error_msg = "Invalid character in numeric value\n";
			return ;
		}
		i++;
	}
}
