/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   safe_atof.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 18:53:57 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/06 17:51:38 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	safe_atof(char *str)
{
	check_numeric(str);
	return (ft_atof(str));
}
