/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:50:52 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:43:46 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_file(char *filename, t_scene *scene)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 3 || ft_strncmp(filename + len - 3, ".rt", 3) != 0)
	{
		scene->parser.error = 1;
		scene->parser.error_msg = "File must end with .rt extension\n";
		return ;
	}
}
