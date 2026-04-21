/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:32:28 by lderks            #+#    #+#             */
/*   Updated: 2026/04/20 18:11:26 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include "structs.h"

// create
t_vector			vec_c_default(void);
t_vector			vec_c_copy(t_vector vector);
t_vector			vec_c_xyz(float x, float y, float z);
t_vector			vec_c_single(float single);

// squared
float				squared(float number);	//move to diff file?

// length
float				length_square(t_vector vector);
float				length_square_r(t_vector vector);

// normalize
void				v_normalize(t_vector *vector);
t_vector			v_normalized(t_vector vector);

// Dot- & Cross-product
float				dot_product(t_vector vec_1, t_vector vec_2);
t_vector			cross_product(t_vector vec_1, t_vector vec_2);

// Modifying operations
void				v_mod_equal(t_vector *vec_1, t_vector *vec_2);
void				v_mod_add(t_vector *vec_1, t_vector *vec_2);
void				v_mod_subtr(t_vector *vec_1, t_vector *vec_2);
void				v_mod_multi(t_vector *vec_1, float nbr);
void				v_mod_divide(t_vector *vec_1, float nbr);

// New vector operations
t_vector			v_new_negative(t_vector vector);
t_vector			v_new_addition(t_vector vec_1, t_vector vec_2);
t_vector			v_new_subtraction(t_vector vec_1, t_vector vec_2);
t_vector			v_new_multiply(t_vector vec_1, t_vector vec_2);
t_vector			v_new_multiply_float(t_vector vec_1, float nbr);
t_vector			v_new_divide(t_vector vec_1, t_vector vec_2);

// New screen coordinate
t_screen_coordinate	v_screen_zero(void);
t_screen_coordinate	v_screen_copy(t_screen_coordinate vec);
t_screen_coordinate	v_screen_xy(float x, float y);

#endif
