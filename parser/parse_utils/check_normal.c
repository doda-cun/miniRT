/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_normal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 19:02:31 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/06 17:51:03 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_normal(double normal)
{
	if (normal < -1.0 || normal > 1.0)
	{
		write(2, "Error\nNormal vector must be between -1.0 and 1.0\n", 49);
		exit(1);
	}
}
