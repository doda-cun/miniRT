/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_parts.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/16 17:31:11 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/06 17:50:49 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_parts(char **parts, int expected)
{
	int	i;

	i = 0;
	while (parts[i])
		i++;
	if (i < expected)
	{
		free_split(parts);
		write(2, "Error\nMissing fields in scene elements.\n", 38);
		exit(1);
	}
}
