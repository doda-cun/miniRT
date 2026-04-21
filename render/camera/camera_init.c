/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/03 18:18:42 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/21 13:46:29 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "vectors.h"

void	camera_init(t_camera *cam)
{
	t_vector	world_up;
	t_vector	up_alt;

	cam->dir = v_normalized(cam->dir);
	world_up = vec_c_xyz(0.0f, 1.0f, 0.0f);
	up_alt = vec_c_xyz(0.0f, 0.0f, 1.0f);
	if (fabsf(dot_product(cam->dir, world_up)) > 0.999f)
		world_up = up_alt;
	cam->right = v_normalized(cross_product(world_up, cam->dir));
	cam->up = cross_product(cam->dir, cam->right);
	cam->half_h = tanf(cam->fov * M_PI / 180.0f / 2.0f);
	cam->half_w = cam->half_h * ((float)WIDTH / (float)HEIGHT);
}
/*	world_up = upguide
	cam->right = right and left
	cam->up =  true up vector
	cam->half_h = half the height * (convertsion to radian)*/
