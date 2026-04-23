/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:58:50 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:33:06 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_fov(int fov, t_scene *scene)
{
	if (fov < 0 || fov > 180)
	{
		scene->parser.error = 1;
		scene->parser.error_msg = "FOV value must be between 0 and 180\n";
		return ;
	}
}
