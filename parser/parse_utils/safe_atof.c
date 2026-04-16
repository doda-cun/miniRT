/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:53:57 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/16 17:40:37 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	safe_atof(char *str)
{
	double	value;

	check_numeric(str);
	if (ft_strlen(str) > 10)
	{
		write(2, "Error\nFloat value out of range\n", 31);
		exit(1);
	}
	value = ft_atof(str);
	if (value > INT_MAX || value < INT_MIN)
	{
		write(2, "Error\nInteger value out of range\n", 33);
		exit(1);
	}
	return (value);
}
