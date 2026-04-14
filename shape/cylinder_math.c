/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 16:36:01 by lderks            #+#    #+#             */
/*   Updated: 2026/04/14 14:57:20 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	set_cylinder_math(t_cylinder *cylinder, t_intersection *intersection,
						t_cylinder_math *c_math)
{
	c_math->origin_to_base = v_new_subtraction(intersection->ray.origin,
			cylinder->center);
	c_math->v_perp = v_new_subtraction(intersection->ray.direction,
			v_new_multiply_float(cylinder->axis,
				dot_product(intersection->ray.direction, cylinder->axis)));
	c_math->dp_perp = v_new_subtraction(c_math->origin_to_base,
			v_new_multiply_float(cylinder->axis,
				dot_product(c_math->origin_to_base, cylinder->axis)));
	c_math->a = dot_product(c_math->v_perp, c_math->v_perp);
	c_math->b = 2.0f * dot_product(c_math->v_perp, c_math->dp_perp);
	c_math->c = dot_product(c_math->dp_perp, c_math->dp_perp)
		- squared(cylinder->radius);
	c_math->discriminant = squared(c_math->b) - 4.0f * c_math->a * c_math->c;
}
