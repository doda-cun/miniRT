/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_hit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/27 14:13:28 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/03 14:02:27 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

int	intersection_hit(const t_intersection *intersection)			//remove const?? not needed only good practice
{
	return(intersection->shape != NO_HIT);	
}