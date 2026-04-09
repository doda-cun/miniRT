/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_shapeset_intersect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:11:05 by lderks            #+#    #+#             */
/*   Updated: 2026/04/09 18:50:55 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "vectors.h"


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
