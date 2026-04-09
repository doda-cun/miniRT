/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_calc_position.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/27 14:14:03 by lderks        #+#    #+#                 */
/*   Updated: 2026/03/27 14:26:55 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

t_point	intersection_position(const t_intersection *intersection)			//remove const?? not needed only good practice
{
	return (ray_calculate_length(&intersection->ray, intersection->length));
}