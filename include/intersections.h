/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:24:38 by lderks            #+#    #+#             */
/*   Updated: 2026/04/20 17:48:10 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "structs.h"

// create intersection
t_intersection	i_create_default(void);
t_intersection	i_create_from_ray(t_ray Ray);

// calculate pos
t_point			intersection_position(const t_intersection *intersection);

// check_hit -> for code readability, idk if its needed
int				intersection_hit(const t_intersection *intersection);

#endif
