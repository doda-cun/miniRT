/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_ratio.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 18:26:37 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/06 17:51:09 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_ratio(double ratio)
{
	if (ratio < 0.0 || ratio > 1.0)
	{
		write(2, "Error\nRatio must be between 0.0 and 1.0\n", 40);
		exit(1);
	}
}
