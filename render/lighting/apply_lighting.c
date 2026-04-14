/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:48:12 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/14 15:21:10 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_color	apply_lighting(t_color color, t_ambient ambient, double diffuse)
{
	t_color	result;
	double	brightness;

	brightness = ambient.ratio + diffuse;
	if (brightness > 1.0)
		brightness = 1.0; //cannot be brighter than 100%
	result.r = (int)(color.r * brightness);
	result.g = (int)(color.g * brightness);
	result.b = (int)(color.b * brightness);
	return (result);
}

/* the more directly a surface faces the light the brighter it is.
surface faces directly toeard light -> diffuse = 1.0 = max brightness
surface at 45 degress to light -> diffuse = 0.5 -> half brightness
surface faces away from light -> diffuse = 0.0 -> no diffuse light

then multiply by the light brighness from the scne
diffuse = diffuse *Scene->light.brightness*/

