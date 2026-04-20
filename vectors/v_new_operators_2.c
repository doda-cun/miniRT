/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_new_operators_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:25:57 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/20 18:45:10 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	v_new_negative(t_vector vector)
{
	t_vector	negative;

	negative.x = -vector.x;
	negative.y = -vector.y;
	negative.z = -vector.z;
	return (negative);
}

t_vector	v_new_divide_float(t_vector vec_1, float nbr)
{
	t_vector	new_vec;

	new_vec.x = vec_1.x / nbr;
	new_vec.y = vec_1.y / nbr;
	new_vec.z = vec_1.z / nbr;
	return (new_vec);
}
