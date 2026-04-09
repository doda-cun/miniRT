/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_to_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/24 15:21:04 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/03 15:15:45 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	color_to_hex(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}
/* mlx expects color as a single int
shifting bits so every color moves to its own lane
then | to combine theminto one number */
