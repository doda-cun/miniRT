/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 17:33:19 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/23 18:19:56 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_scene(char *filename, t_scene *scene)
{
	int		fd;
	char	*line;

	check_file(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCould not open file\n", 25);
		exit(1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		parse_line(line, scene);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	check_required(scene); 
}