/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:43:35 by lderks            #+#    #+#             */
/*   Updated: 2026/04/14 15:02:07 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "structs.h"
# include "vectors.h"

// create ray
t_ray	ray_c_default(void);
t_ray	ray_c_copy(t_ray ray);
t_ray	ray_c_new(t_point origin, t_vector direction, float t_max);

// calculate length
t_point	ray_calculate_length(const t_ray *ray, float t);

#endif
