/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_vector_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:32:49 by lderks            #+#    #+#             */
/*   Updated: 2026/04/14 15:01:18 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vectors.h"

t_screen_coordinate	v_screen_zero(void)
{
	t_screen_coordinate	coordinate;

	coordinate.x = 0.0;
	coordinate.y = 0.0;
	return (coordinate);
}

t_screen_coordinate	v_screen_copy(t_screen_coordinate vec)
{
	t_screen_coordinate	coordinate;

	coordinate.x = vec.x;
	coordinate.y = vec.y;
	return (coordinate);
}

t_screen_coordinate	v_screen_xy(float x, float y)
{
	t_screen_coordinate	coordinate;

	coordinate.x = x;
	coordinate.y = y;
	return (coordinate);
}
