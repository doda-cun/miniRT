/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sphere_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:03:07 by lderks            #+#    #+#             */
/*   Updated: 2026/04/10 18:38:06 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

// *sphere_create(t_point centre, float radius)
// {
// 	t_sphere	*sphere;
// 	//sphere = malloc(sizeof(t_sphere));
// 	sphere->shape.type = SPHERE;
// 	sphere->shape.full_intersection = &sphere_full_intersect;
// 	sphere->shape.single_intersection = &sphere_single_intersect;
// 	sphere->centre = centre;
// 	//sphere->radius = radius;
// 	return (sphere);
// }

//why are we creating a new spehere?

/*sphere_create mallocs a new sphere and sets the function pointers on that malloc'd copy.
 But your parser fills in scene->sphere[i] directly, not the malloc'd one.
  So you have two separate spheres
 — the parser fills one, sphere_create creates another, and they never connect.*/
