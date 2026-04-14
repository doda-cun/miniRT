/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_length.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:13:08 by lderks            #+#    #+#             */
/*   Updated: 2026/04/14 15:00:06 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

float	length_square(t_vector vector)
{
	return (squared(vector.x) + squared(vector.y) + squared(vector.z));
}

float	length_square_r(t_vector vector)
{
	return (sqrtf(length_square(vector)));		//this gives a double, not a float. -> different approach needed?
}
