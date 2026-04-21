/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_normalize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:21:16 by lderks            #+#    #+#             */
/*   Updated: 2026/04/20 18:48:22 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

void	v_normalize(t_vector *vector)
{
	float	length;

	length = length_square_r(*vector);
	if (length == 0)
		return ;
	vector->x = vector->x / length;
	vector->y = vector->y / length;
	vector->z = vector->z / length;
}

t_vector	v_normalized(t_vector vector)
{
	float	length;

	length = length_square_r(vector);
	if (length == 0)
		return (vector);
	vector.x = vector.x / length;
	vector.y = vector.y / length;
	vector.z = vector.z / length;
	return (vector);
}
