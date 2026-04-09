/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   safe_atoi.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/12 18:57:31 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/06 17:51:43 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	safe_atoi(char *str)
{
	check_numeric(str);
	return (ft_atoi(str));
}
