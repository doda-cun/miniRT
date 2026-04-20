/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:50:52 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/20 18:12:49 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 3 || ft_strncmp(filename + len - 3, ".rt", 3) != 0)
	{
		write (2, "Error\nFile must end with .rt extension\n", 39);
		exit(1);
	}
}
