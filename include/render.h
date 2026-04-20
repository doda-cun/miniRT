/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:48:38 by lderks            #+#    #+#             */
/*   Updated: 2026/04/20 18:49:06 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "structs.h"
# include "mlx.h"

//render
void	render(t_mlx *mlx, t_scene *scene);

//Mlx win
int		close_window(void *param);
int		esc_key_hook(int keycode, void *param);

//camera
void	camera_init(t_camera *cam);
t_ray	camera_make_ray(t_camera *cam, int x, int y);

//color
int		color_to_hex(t_color color);

//light
t_color	apply_ambient(t_color color, t_ambient ambient);
t_color	apply_lighting(t_color color, t_ambient ambient, double diffuse);
t_color	get_sphere_color(t_sphere *sphere, t_intersection *intersection);
t_color	get_plane_color(t_plane *plane, t_intersection *intersection);
t_color	get_cylinder_color(t_cylinder *cylinder, t_intersection *intersection);
int		is_in_shadow(t_scene *scene, t_point hit_point, t_vector normal);

#endif
