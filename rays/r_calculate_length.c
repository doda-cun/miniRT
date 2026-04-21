/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_calculate_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:03:18 by lderks            #+#    #+#             */
/*   Updated: 2026/04/20 18:47:34 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_point	ray_calculate_length(const t_ray *ray, float t)
{
	t_point	point_on_ray;

	point_on_ray = v_new_multiply_float(ray->direction, t);
	return (v_new_addition(ray->origin, point_on_ray));
}
/*point_on_ray used to find point t of a intersection.
t = where along the ray is the intersection*/
