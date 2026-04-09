/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_ray.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/19 17:30:27 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/03 17:02:55 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_ray	get_ray(t_scene *scene, int x, int y)
{
	t_ray	ray;
	double	half_w;
	double	pixel_x;
	double	pixel_y;

	half_w = tan(scene->camera.fov * M_PI / 180.0 / 2.0);
	pixel_x = ((x - WIDTH / 2.0) / (WIDTH / 2.0)) * half_w;
	pixel_y = -((y - HEIGHT /2.0) / (WIDTH/ 2.0)) * half_w;
	ray.origin = scene->camera.pos; // every ray starts from the camera position
	ray.direction = get_ray_dir(scene->camera.dir, pixel_x, pixel_y);
	return (ray);
}

/* builds one ray for a specific pixel (x,y) on screen*/
/*half_w converts radians to degrees and divides by 2
as we only need to cover half the screen -
from center to the right edge */

/*multiply by pi is to convert degrees to radians*/

/*pixel x and y are conversion from pixel to viewpoint coordinates*/
/*raw pixel go from 0  to 1280 (width given)
but we want to be center at 0 so range is -640 and +640
so first we normalize then we scale by multiplying with the half_w*/

/* the final number is pixel_x the actual posiiton in 3D that
the ray needs to pass through.*/
