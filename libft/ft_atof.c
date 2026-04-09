/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:06:42 by doda-cun          #+#    #+#             */
/*   Updated: 2026/03/10 18:10:10 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	result = 0.0;
	decimal = 0.0;
	sign = 1;
	i = 0;
	if (str[i] == '-' && ++i)
		sign = -1;
	while (str[i] && str[i] != '.')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	decimal = 0.1;
	while (str[i])
	{
		result += (str[i++] - '0') * decimal;
		decimal *= 0.1;
	}
	return (result * sign);
}
