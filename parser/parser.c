/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:33:19 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/24 19:15:56 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_scene(char *filename, t_scene *scene)
{
	int		fd;
	char	*line;

	check_file(filename, scene);
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
		if (scene->parser.error)
		{
			get_next_line(-1);
			close(fd);
			check_required(scene);
		}
		line = get_next_line(fd);
	}
	close(fd);
	check_required(scene);
}
