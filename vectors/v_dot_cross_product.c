/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_dot_cross_product.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:46:35 by lderks            #+#    #+#             */
/*   Updated: 2026/04/14 14:59:30 by doda-cun         ###   ########.fr       */
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
