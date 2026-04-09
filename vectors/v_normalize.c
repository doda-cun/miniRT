/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_normalize.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 14:21:16 by lderks        #+#    #+#                 */
/*   Updated: 2026/03/24 18:02:05 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

void	v_normalize(t_vector *vector)
{
	float	length;
	length = length_square_r(*vector);
	if (length == 0)						//don't divide by 0
		return;
	vector->x = vector->x / length;
	vector->y = vector->y / length;
	vector->z = vector->z / length;
}

t_vector	v_normalized(t_vector vector)
{
	float	length;
	length  = length_square_r(vector);
	if (length == 0)
		return (vector);
	vector.x = vector.x / length;
	vector.y = vector.y / length;
	vector.z = vector.z / length;
	return (vector);
}

