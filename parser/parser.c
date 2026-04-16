/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 17:33:19 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/16 18:01:10 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_scene(char *filename, t_scene *scene)
{
	int		fd;
	char	*line;
										//make these functions give parser and scene structs
	check_file(filename);
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
	check_required(scene);
}
