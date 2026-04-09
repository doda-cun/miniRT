/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_dot_cross_product.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 14:46:35 by lderks        #+#    #+#                 */
/*   Updated: 2026/03/26 18:13:23 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

float	dot_product(t_vector vec_1, t_vector vec_2)
{
	float	dot_product;
	
	dot_product = vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z;
	return (dot_product);
}

t_vector	cross_product(t_vector vec_1, t_vector vec_2)
{
	return (vec_c_xyz(vec_1.y * vec_2.z - vec_1.z * vec_2.y,
					vec_1.z * vec_2.x - vec_1.x * vec_2.z,
					vec_1.x * vec_2.y - vec_1.y * vec_2.x));
}