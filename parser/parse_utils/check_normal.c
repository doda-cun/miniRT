/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:02:31 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:45:45 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_normal(double normal, t_scene *scene)
{
	if (normal < -1.0 || normal > 1.0)
	{
		scene->parser.error = 1;
		scene->parser.error_msg = "Normal vec must be between -1.0 and 1.0\n";
		return ;
	}
}
