/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:13:53 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/07/19 14:13:53 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_options(void)
{
	ft_putendl_fd("\tM - Mandelbrot", 1);
	ft_putendl_fd("\tB - Burning Ship", 1);
	ft_putendl_fd("./fractol <type>", 1);
	ft_putendl_fd("\tJ - Julia", 1);
	ft_putendl_fd("For Julia: ./fractol <type> 0.28 0.13", 1);
}

void	color_options(void)
{
	ft_putendl_fd("Provide color as a hex RRGGBB format:", 1);
	ft_putendl_fd("./fractol <type> <color>", 1);
	ft_putendl_fd("./fractol M 0066FF\e[0m", 1);
	ft_putendl_fd("./fractol J 0.285 0.01 CC6600\e[0m", 1);
}

void	help_msg(t_data *fract)
{
	ft_putendl_fd("Fract'ol Help & Keybindings", 1);
	fractal_options();
	color_options();
	exit_free(EXIT_FAILURE, fract);
}
