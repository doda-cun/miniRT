/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:57:31 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/16 17:45:35 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	safe_atoi(char *str)
{
	long	value;

	check_numeric(str);
	if (ft_strlen(str) > 10)
	{
		write(2, "Error\nInt value out of range\n", 31);
		exit(1);
	}
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
	{
		write(2, "Error\nInteger value out of range\n", 33);
		exit(1);
	}
	return ((int)value);
}
