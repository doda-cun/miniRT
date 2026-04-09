/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 17:43:35 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/03 14:43:14 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

#include "structs.h"

// create ray
t_ray	ray_c_default();
t_ray	ray_c_copy(t_ray ray);
t_ray	ray_c_new(t_point origin, t_vector direction, float t_max);

// calculate length
t_point	ray_calculate_length(const t_ray *ray, float t);

#endif