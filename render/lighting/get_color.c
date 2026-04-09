/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 16:08:22 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/09 14:44:56 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_color	get_color(t_scene *scene, t_ray ray, double t, int i)
{
	t_vector	hit_point;
	t_vector	normal;
	t_vector	light_dir;
	double		diffuse;

	hit_point = v_new_addition(ray.origin, vec3_scale(ray.dir, t));
	normal = v_normalized(v_new_subtraction(hit_point, scene->sphere[i].centre));
	light_dir = v_normalized(v_new_substraction(scene->light.pos, hit_point));
	diffuse = dot_product(normal, light_dir) * scene->light.brightness;
	if (diffuse < 0)
		diffuse = 0;
	return (apply_lighting(scene->sphere[i].color, scene->ambient, diffuse));
}



// ONLY WORKS FOR SPHERES, SO NOT USEFUL NEED TO CHANGE



/* step 1 : find where the ray hit (hit poiny)
		we know where the ray started (ray.origin) , in which way it went (ray.dir)
		and how far it traveled (t)
		so we cna find the exact 3d point where it hit.
	step 2: find which wya the surface faces (normal)
		now we know where the ray hit the sphere, we now need to find out
		which way the surface faces at that point(normal). For a sphere the
		normal point always points straight out from the center to the hit point.
		we subtract to get the direction from center to hit point; b to a
	step 3 : find which way the light is (light_dir)
		you have the light positio from the scene - scene->light.pos -
		we want an arroy poiting from the hit point toward the light;
		normalize becuse we only care to know in which direction light is not how
		far away it is.
	step 4 : dot product for brightness (diffuse)
		now we compare normal and light_dir. dot products gives -1 to 1 the
		multipilcation with light brightness sclaes by how strong the light is.
	step 5: clamp negative values
		you cant have negative brightness; the darkest it can be is jut the ambient light,nver below that.
		in real lief a surface facing away from the light just gets not light , it doesnt get 'anti-light'
	step 6 : combine with ambient */
