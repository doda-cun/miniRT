/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/03 14:48:38 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/06 19:27:07 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "structs.h"
#include "mlx.h"

//render 
void	render(t_mlx *mlx, t_scene *scene);

//Mlx win
int		close_window(void *param);
int		esc_key_hook(int keycode, void *param);

//camera
void    	camera_init(t_camera *cam);
t_ray		get_ray(t_scene *scene, int x, int y);

//color
int		color_to_hex(t_color color);

//light
t_color	apply_ambient(t_color color, t_ambient ambient);
t_color	apply_lighting(t_color color, t_ambient ambient, double diffuse);
t_color	get_color(t_scene *scene, t_ray ray, double t, int i);

#endif