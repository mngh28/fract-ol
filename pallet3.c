/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pallet3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:14:05 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/07/19 14:14:05 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	opposite(t_data *fract, int color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	i = -1;
	while (++i < MAX_ITERATIONS)
	{
		fract->palette[i] = 0;
		r += i % 0xFF;
		g += i % 0xFF;
		b += i % 0xFF;
		fract->palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
	}
	fract->palette[MAX_ITERATIONS - 1] = 0;
}

void	contrast(t_data *fract, int color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	i = -1;
	while (++i < MAX_ITERATIONS)
	{
		fract->palette[i] = 0;
		if (r != 0xFF)
			r += i % 0xFF;
		if (g != 0xFF)
			g += i % 0xFF;
		if (b != 0xFF)
			b += i % 0xFF;
		fract->palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
	}
	fract->palette[MAX_ITERATIONS - 1] = 0;
}

void	graphic(t_data *fract, int color)
{
	int	i;
	int	rgb[3];

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	i = -1;
	while (rgb[0] < 0x33 || rgb[1] < 0x33 || rgb[2] < 0x33)
	{
		if (rgb[0] != 0xFF)
			rgb[0]++;
		if (rgb[1] != 0xFF)
			rgb[1]++;
		if (rgb[2] != 0xFF)
			rgb[2]++;
	}
	while (++i < MAX_ITERATIONS)
	{
		fract->palette[i] = 0;
		rgb[0] -= i % 0xFF;
		rgb[1] -= i % 0xFF;
		rgb[2] -= i % 0xFF;
		fract->palette[i] = 0xFF << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	}
	fract->palette[MAX_ITERATIONS - 1] = 0;
}
