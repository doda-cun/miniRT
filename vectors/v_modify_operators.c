/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_modify_operators.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 16:40:35 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/14 15:27:41 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

//mod = Modify. Keep the same vector and modify it.

void	v_mod_equal(t_vector *vec_1, t_vector *vec_2)
{
	vec_1->x = vec_2->x;
	vec_1->y = vec_2->y;
	vec_1->z = vec_2->z;
}

void	v_mod_add(t_vector *vec_1, t_vector *vec_2)
{
	vec_1->x += vec_2->x;
	vec_1->y += vec_2->y;
	vec_1->z += vec_2->z;
}
void	v_mod_subtr(t_vector *vec_1, t_vector *vec_2)
{
	vec_1->x -= vec_2->x;
	vec_1->y -= vec_2->y;
	vec_1->z -= vec_2->z;
}
void	v_mod_multi(t_vector *vec_1, float nbr)
{
	vec_1->x *= nbr;
	vec_1->y *= nbr;
	vec_1->z *= nbr;
}

void	v_mod_divide(t_vector *vec_1, float nbr)
{
	vec_1->x /= nbr;
	vec_1->y /= nbr;
	vec_1->z /= nbr;
}

t_vector	v_new_negative(t_vector vector)				//6th function, illigal
{
	t_vector negative;
	negative.x = -vector.x;
	negative.y = -vector.y;
	negative.z = -vector.z;
	return (negative);
}