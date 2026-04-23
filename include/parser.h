/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/03 14:45:28 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/23 17:13:47 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "structs.h"
# include "libft.h"

//Parser
void		parse_scene(char *filename, t_scene *scene);
void		parse_line(char *line, t_scene *scene);
void		parse_ambient(char *line, t_scene *scene);
void		parse_camera(char *line, t_scene *scene);
void		parse_light(char *line, t_scene *scene);
void		parse_sphere(char *line, t_scene *scene);
void		parse_plane(char *line, t_scene *scene);
void		parse_cylinder(char *line, t_scene *scene);

//Parser Utils
t_color		parse_color(char *str);
t_vector	parse_vector(char *str);
void		free_split(char **split);
void		check_ratio(double ratio);
void		check_numeric(char *str);
void		check_file(char *filename);
void		check_color(t_color color);
double		safe_atof(char *str);
double		safe_atoi(char *str);
void		check_fov(int fov);
void		check_normal(double normal);
t_vector	parse_normal(char *str);
void		check_required(t_scene *scene);
void		check_parts(char **parts, int expected);
void		check_count_shapes(t_scene *s);

#endif
