/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:26:37 by doda-cun          #+#    #+#             */
/*   Updated: 2026/04/23 18:43:33 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_ratio(double ratio, t_scene *scene)
{
	if (ratio < 0.0 || ratio > 1.0)
	{
		scene->parser.error = 1;
		scene-> parser.error_msg = "Ratio must be between 0.0 and 1.0\n";
		return ;
	}
}
