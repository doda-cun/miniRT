/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_parts.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/16 17:31:11 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/23 18:52:23 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_parts(char **parts, int expected, t_scene *scene)
{
	int	i;

	i = 0;
	while (parts[i])
		i++;
	if (i != expected)
	{
		scene->parser.error = 1;
		scene->parser.error_msg = "Missing fields in scene elements.\n";
		return ;
	}
}
