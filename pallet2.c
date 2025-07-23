/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pallet2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:14:01 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/07/19 14:14:01 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fill_stripe(t_data *fract, int color, int stripe)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		fract->palette[i] = color;
		i += stripe;
	}
}

int	color_get(int color, double percent)
{
	int		rgb[3];
	int		trgb[3];
	double	percentage;

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	percentage = (percent / 100) * 256;
	trgb[0] = (rgb[0] + percentage) - 256;
	trgb[1] = (rgb[1] + percentage) - 256;
	trgb[2] = (rgb[2] + percentage) - 256;
	return (0xFF << 24 | trgb[0] << 16 | trgb[1] << 8 | trgb[2]);
}

void	zebra(t_data *fract, int color)
{
	int	color2;

	color2 = color_get(color, 50);
	fill_stripe(fract, color, 1);
	fill_stripe(fract, color2, 2);
	fract->palette[MAX_ITERATIONS - 1] = 0;
}

void	triad(t_data *fract, int color)
{
	int		triad[2];

	triad[0] = color_get(color, 33);
	triad[1] = color_get(color, 66);
	fill_stripe(fract, color, 1);
	fill_stripe(fract, triad[0], 2);
	fill_stripe(fract, triad[1], 3);
	fract->palette[MAX_ITERATIONS - 1] = 0;
}

void	tetra(t_data *fract, int color)
{
	int	tetra[3];

	tetra[0] = color_get(color, 25);
	tetra[1] = color_get(color, 50);
	tetra[2] = color_get(color, 75);
	fill_stripe(fract, color, 1);
	fill_stripe(fract, tetra[0], 2);
	fill_stripe(fract, tetra[1], 3);
	fill_stripe(fract, tetra[2], 4);
	fract->palette[MAX_ITERATIONS - 1] = 0;
}
