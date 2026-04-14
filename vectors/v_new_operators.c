/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_new_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:16:45 by lderks            #+#    #+#             */
/*   Updated: 2026/04/14 15:25:56 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	v_new_addition(t_vector vec_1, t_vector vec_2)
{
	t_vector	new_vec;

	new_vec.x = vec_1.x + vec_2.x;
	new_vec.y = vec_1.y + vec_2.y;
	new_vec.z = vec_1.z + vec_2.z;
	return (new_vec);
}

t_vector	v_new_subtraction(t_vector vec_1, t_vector vec_2)
{
	t_vector	new_vec;

	new_vec.x = vec_1.x - vec_2.x;
	new_vec.y = vec_1.y - vec_2.y;
	new_vec.z = vec_1.z - vec_2.z;
	return (new_vec);
}

t_vector	v_new_multiply(t_vector vec_1, t_vector vec_2)
{
	t_vector	new_vec;

	new_vec.x = vec_1.x * vec_2.x;
	new_vec.y = vec_1.y * vec_2.y;
	new_vec.z = vec_1.z * vec_2.z;
	return (new_vec);
}

t_vector	v_new_multiply_float(t_vector vec_1, float nbr)
{
	t_vector	new_vec;

	new_vec.x = vec_1.x * nbr;
	new_vec.y = vec_1.y * nbr;
	new_vec.z = vec_1.z * nbr;
	return (new_vec);
}

t_vector	v_new_divide(t_vector vec_1, t_vector vec_2)
{
	t_vector	new_vec;

	new_vec.x = vec_1.x / vec_2.x;
	new_vec.y = vec_1.y / vec_2.y;
	new_vec.z = vec_1.z / vec_2.z;
	return (new_vec);
}


