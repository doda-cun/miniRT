/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   apply_ambient.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 15:32:15 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/03 15:00:56 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_color	apply_ambient(t_color color, t_ambient ambient)
{
	t_color	result;

	result.r = (int)(color.r * ambient.ratio);
	result.g = (int)(color.g * ambient.ratio);
	result.b = (int)(color.b * ambient.ratio);
	return (result);
}

/*ambient light us the base birghtness, every surface gets it

formula: final_color = object_color * ambient_ratio

since ambient raito is a double but color expects int we cast it to
truncate the decimal
ambient ratio alone gives a dim base */
