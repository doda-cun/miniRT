/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_shapeset_intersect.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/02 17:11:05 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/02 17:17:17 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

int shapeset_full_intersect(t_shapeset *set, t_intersection *intersection)
{
	int	did_hit;
	int	i;

	did_hit = 0;
	i = 0;
	while (i < set->count)
	{
		if(set->shapes[i]->full_intersection(set->shapes[i], intersection))
			did_hit = 1;
		i++;
	}
	return (did_hit);
}