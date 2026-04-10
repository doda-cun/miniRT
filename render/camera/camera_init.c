/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:18:42 by lderks            #+#    #+#             */
/*   Updated: 2026/04/10 18:08:33 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "vectors.h"

void    camera_init(t_camera *cam)
{
    t_vector    world_up;

    cam->dir = v_normalized(cam->dir);
    world_up = vec_c_xyz(0.0f, 1.0f, 0.0f);								//upguide
    cam->right = v_normalized(cross_product(world_up, cam->dir));		//right and left
    cam->up = cross_product(cam->dir, cam->right);						// true up vector
    cam->half_h = tanf(cam->fov * M_PI / 180.0f / 2.0f);				//half the height * (convertsion to radian)

    cam->half_w = cam->half_h * ((float)WIDTH / (float)HEIGHT);		//can't we just hardcode this?
}
