/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:45:28 by lderks            #+#    #+#             */
/*   Updated: 2026/04/24 18:59:59 by doda-cun         ###   ########.fr       */
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
t_color		parse_color(char *str, t_scene *scene);
t_vector	parse_vector(char *str, t_scene *scene);
void		free_split(char **split);
void		check_ratio(double ratio, t_scene *scene);
void		check_numeric(char *str, t_scene *scene);
void		check_file(char *filename, t_scene *scene);
void		check_color(t_color color, t_scene *scene);
double		safe_atof(char *str, t_scene *scene);
double		safe_atoi(char *str, t_scene *scene);
void		check_fov(int fov, t_scene *scene);
void		check_normal(double normal, t_scene *scene);
t_vector	parse_normal(char *str, t_scene *scene);
void		check_required(t_scene *scene);
void		check_parts(char **parts, int expected, t_scene *scene);
void		check_count_shapes(t_scene *s);
int			parts_error(char **parts, int expected, t_scene *scene);


#endif
