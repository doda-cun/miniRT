/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_create.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:39:20 by lderks            #+#    #+#             */
/*   Updated: 2026/04/20 18:36:55 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vectors.h"

t_vector	vec_c_default(void)
{
	t_vector	vector;

	vector.x = 0.0;
	vector.y = 1.0;
	vector.z = 0.0;
	return (vector);
}

t_vector	vec_c_copy(t_vector vector)
{
	t_vector	copy;

	copy.x = vector.x;
	copy.y = vector.y;
	copy.z = vector.z;
	return (copy);
}

t_vector	vec_c_xyz(float x, float y, float z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vector	vec_c_single(float single)
{
	t_vector	vector;

	vector.x = single;
	vector.y = single;
	vector.z = single;
	return (vector);
}
