/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:14:03 by lderks            #+#    #+#             */
/*   Updated: 2026/04/20 18:43:45 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"
#include "rays.h"

t_point	intersection_position(const t_intersection *intersection)
{
	return (ray_calculate_length(&intersection->ray, intersection->length));
}
