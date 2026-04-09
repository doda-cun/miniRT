/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 18:28:19 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/06 17:50:54 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_color(t_color color)
{
	if (color.r < 0 || color.r > 255
		|| color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255)
	{
		write(2, "Error\nColor values must be between 0 and 255\n", 45);
		exit(1);
	}
}
