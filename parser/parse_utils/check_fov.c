/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_fov.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 18:58:50 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/06 17:50:59 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_fov(int fov)
{
	if (fov < 0 || fov > 180)
	{
		write(2, "Error\nFOV must be between 0 and 180\n", 36);
		exit(1);
	}
}
