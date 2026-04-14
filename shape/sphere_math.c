/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:43:15 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/14 13:53:00 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	set_sphere_math(t_sphere *sphere, t_intersection *intersection,
						t_sphere_math *s_math)
{
	s_math->local_ray = intersection->ray;
	s_math->local_ray.origin = v_new_subtraction(s_math->local_ray.origin,
			sphere->centre);
	s_math->a = length_square(s_math->local_ray.direction);
	s_math->b = 2 * dot_product(s_math->local_ray.direction,
			s_math->local_ray.origin);
	s_math->c = length_square(s_math->local_ray.origin)
		- squared(sphere->radius);
	s_math->discriminant = squared(s_math->b) - 4 * s_math->a * s_math->c;
}
