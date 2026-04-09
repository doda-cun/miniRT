/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 17:33:19 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/09 15:02:54 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_scene(char *filename, t_scene *scene)
{
	int		fd;
	char	*line;		
										//make these functions give parser and scene structs
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCould not open file\n", 25);
		exit(1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		parse_line(line, scene);
		free(line);
	}
	close(fd);
	check_required(scene);			//added shapes_count check
//	printf("=== PARSE RESULTS ===\n");
//	printf("=== AMBIENT ===\n");
//	printf("ambient ratio: %f\n", scene->ambient.ratio);
//	printf("ambient color: %d %d %d\n", scene->ambient.color.r, scene->ambient.color.g, scene->ambient.color.b);
//	printf("=== CAMERA ===\n");
//	printf("camera pos: %f %f %f\n", scene->camera.pos.x, scene->camera.pos.y, scene->camera.pos.z);
//	printf("camera direction: %f, %f, %f\n", scene->camera.dir.x, scene->camera.dir.y, scene->camera.dir.z);
//	printf("camera fov: %d\n", scene->camera.fov);
//	printf("=== LIGHT ===\n");
//	printf ("Light pos: %f, %f, %f\n", scene->light.pos.x, scene->light.pos.y, scene->light.pos.z);
//	printf("Light brightness: %f\n", scene->light.brightness);
//	printf("LighT unused colors : %d, %d, %d \n", scene->light.color.r, scene->light.color.g, scene->light.color.b);
//	printf("=== SPHERE ===\n");
//	printf("sphere center: %f %f %f\n", scene->sphere[0].center.x, scene->sphere[0].center.y, scene->sphere[0].center.z);
//	printf("sphere diameter: %f\n", scene->sphere[0].diameter);
//	printf("sphere colors: %d, %d, %d\n", scene->sphere[0].color.r, scene->sphere[0].color.g, scene->sphere[0].color.b);
//	printf("sphere count: %d\n", scene->sphere_count);
//	printf("sphere center: %f %f %f\n", scene->sphere[0].center.x,
//    scene->sphere[0].center.y, scene->sphere[0].center.z);
//	printf("sphere diameter: %f\n", scene->sphere[0].diameter);
//	printf("=== PLANE ===\n");
//	printf("Plane pos: %f %f %f\n", scene->plane[0].point.x, scene->plane[0].point.y, scene->plane[0].point.z);
//	printf("plane  vector: %f, %f, %f\n", scene->plane[0].normal.x, scene->plane[0].normal.y, scene->plane[0].normal.z);
//	printf("plane colors: %d, %d, %d\n", scene->plane[0].color.r, scene->plane[0].color.g, scene->plane[0].color.b);
//	printf("=== CYLINDER ===\n");
//	printf("cyliner coordinates: %f, %f, %f\n", scene->cylinder[0].center.x, scene->cylinder[0].center.y, scene->cylinder[0].center.z);
//	printf("cylinder vector: %f, %f, %f\n", scene->cylinder[0].axis.x, scene->cylinder[0].axis.y, scene->cylinder[0].axis.z);
//	printf("cylinder diameter: %f\n", scene->cylinder[0].diameter);
//	printf("cylinder height: %f\n", scene->cylinder[0].height);
//	printf("cylinder colors: %d, %d, %d\n", scene->cylinder[0].color.r,scene->cylinder[0].color.g, scene->cylinder[0].color.b );
}
