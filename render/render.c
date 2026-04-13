/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:26:04 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/10 18:58:23 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "render.h"
#include "shape.h"
#include <stdio.h>


//void	render(t_mlx *mlx, t_scene *scene)
//{
//	int		x;
//	int		y;
//	t_ray	ray;
//	double	t;
//	int		i;
//
//	y = 0;
//	while (y < HEIGHT)
//	{
//		x = 0;
//		while (x < WIDTH)
//		{
//			ray = get_ray(scene, x, y);
//			i = 0;
//			while (i < scene->sphere_count)
//			{
//				t = hit_sphere(scene->sphere[i].center,
//					scene->sphere[i].diameter / 2, ray); // well know the ray hit something and how far away it is
//				if (t > 0)
//					mlx_pixel_put(mlx->mlx, mlx->win, x, y,
//						color_to_hex(get_color(scene, ray, t, i)));
//				i++;
//			}
//			x++;
//		}
//		y++;
//	}
//}

void    render(t_mlx *mlx, t_scene *scene)
{
    int             x;
    int             y;
    t_ray           ray;
    t_intersection  intersection;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            ray = camera_make_ray(&scene->camera, x, y);
            intersection = i_create_from_ray(ray);
			intersection.scene = scene;
            if (shapeset_full_intersect(&scene->shapeset, &intersection))
			{
                mlx_pixel_put(mlx->mlx, mlx->win, x, y,
                    color_to_hex(intersection.color));
			}
            x++;
        }
        y++;
    }
}

// void	render(t_mlx *mlx, t_scene *scene)
// {
// 	(void) scene;
// 	int		x;
// 	int		y;
// 	t_ray	ray;
// 	t_vec3	sphere_center;
// 	double	t;
// 	double  half_w;

// 	half_w = tan(scene->camera.fov * M_PI / 180.0 / 2.0);  /* tan(35°) = 0.7 */
// 	printf("half_w: %f\n", half_w);
// 	sphere_center = (t_vec3){0, 0, -1};       // sphere in front of camera
// 	ray.origin = (t_vec3){0, 0, 0};
// 	//ray.origin = scene->camera.pos;
// 	y = 0;
// 	while (y < 720)
// 	{
// 	    x = 0;
// 	    while (x < 1280)
// 	    {
// 	        // convert pixel to -1..1 range
// 	        ray.dir = (t_vec3){
// 	            (x - 640) / 640.0 * half_w,
// 	            -(y - 360) / 640.0 * half_w,
// 	            -1.0
// 	        };
// 	        t = hit_sphere(sphere_center, 0.5, ray);
// 	        if (t > 0) // if the ray hits anything then we draw a pixel
// 	            mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x00FF0000);
// 	        x++;
// 	    }
// 		y++;
// 	}
// }


/*So half_w is just a scaling factor that squishes or stretches
how far apart your rays spread.
Narrow FOV = small half_w = rays stay close together = zoomed in.*/
