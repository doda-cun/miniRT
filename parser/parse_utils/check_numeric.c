/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_numeric.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 18:47:08 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/06 17:51:05 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != '.' && (str[i] < '0' || str[i] > '9'))
		{
			write(2, "Error\nInvalid character in numeric value\n", 41);
			exit(1);
		}
		i++;
	}
}
