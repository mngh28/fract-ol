/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorchange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:12:42 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/07/19 14:12:42 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	special_color_shift(t_data *fract)
{
	int	alt_color;

	if (fract->color == 0xFFFFFF)
		alt_color = 0xCCCCCC;
	else
		alt_color = fract->color;
	if (fract->color_pattern == 5)
		contrast(fract, alt_color);
	else if (fract->color_pattern == 6)
		opposite(fract, fract->color);
	else if (fract->color_pattern == 7)
		graphic(fract, fract->color);
	else if (fract->color_pattern == 8)
		multiple(fract, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}

static void	striped_color_shift(t_data *fract)
{
	if (fract->color_pattern == 2)
		zebra(fract, fract->color);
	else if (fract->color_pattern == 3)
		triad(fract, fract->color);
	else if (fract->color_pattern == 4)
		tetra(fract, fract->color);
	else
		special_color_shift(fract);
}

void	color_shift(t_data *fract)
{
	int	alt_color;

	fract->color_pattern = (fract->color_pattern + 1) % 9;
	redraw(fract);
	if (fract->color == 0x000000)
		alt_color = 0x333333;
	else
		alt_color = fract->color;
	if (fract->color_pattern == 0)
		mono(fract, alt_color);
	else if (fract->color_pattern == 1)
		multiple(fract, (int [4]){0x000000, alt_color,
			color_get(fract->color, 50), 0xFFFFFF}, 4);
	else
		striped_color_shift(fract);
}
