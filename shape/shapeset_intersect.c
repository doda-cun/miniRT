/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapeset_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:11:05 by lderks            #+#    #+#             */
/*   Updated: 2026/04/14 16:06:51 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "vectors.h"
#include <stdio.h>


int	shapeset_full_intersect(t_shapeset *set, t_intersection *intersection)
{
	int	did_hit;
	int	i;

	did_hit = 0;
	i = 0;
	while (i < set->count)
	{
		if (set->shapes[i]->full_intersection(set->shapes[i], intersection))
			did_hit = 1;
		i++;
	}
	return (did_hit);
<<<<<<< HEAD:shape/s_shapeset_intersect.c
}

int	shapeset_single_intersect(t_shapeset *set, const t_ray *ray)
{
	int	i;

	i = 0;
	while (i < set->count)
	{
		if (set->shapes[i]->single_intersection(set->shapes[i], ray))
			return (1);
		i++;
	}
	return (0);
}
=======
}
>>>>>>> ff611ae3a12f93decf25c9f7f6d4f48a0c5bf51c:shape/shapeset_intersect.c
