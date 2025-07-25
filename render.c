/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:14:14 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/07/19 14:14:14 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_color(t_data *fract, int x, int y, int color)
{
	fract->buf[x * 4 + y * WIDTH * 4] = color;
	fract->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	fract->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	fract->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

static int	choose(t_data *fract, double px_real, double px_imaginary)
{
	int	i;

	i = 0;
	if (fract->set == MANDELBROT)
		i = mandelbrot(px_real, px_imaginary);
	else if (fract->set == JULIA)
		i = julia(fract, px_real, px_imaginary);
	else if (fract->set == BURNING_SHIP)
		i = burning_ship(px_real, px_imaginary);
	return (i);
}

void	draw(t_data *fract)
{
	int		x;
	int		y;
	double	px_real;
	double	px_imaginary;
	int		i;

	mlx_clear_window(fract->mlx, fract->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			px_real = fract->min_real + (double)x * (fract->max_real
					- fract->min_real) / WIDTH;
			px_imaginary = fract->max_imaginary + (double)y
				* (fract->min_imaginary - fract->max_imaginary) / HEIGHT;
			i = choose(fract, px_real, px_imaginary);
			set_color(fract, x, y, fract->palette[i]);
		}
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
